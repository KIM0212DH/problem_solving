#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;



int main() {
	vector<int> road[10000];
	int check[10000];
	queue<int> que;

	for (int i{ 0 }; i < 10000; i++) {
		if (i != 0) {
			road[i].push_back(i - 1);
		}
		if (i != 9999) {
			road[i].push_back(i + 1);
		}

		int num = 0;
		int temp = i;

		for (int j{ 0 }; j < 4; j++) {
			num = num * 10 + temp % 10;
			temp = temp / 10;
		}
		road[i].push_back(num);
	}   //그래프 다 만들어 놓음

	int t;
	cin >> t;
	while (t--) {

		for (int i{ 0 }; i < 10000; i++) {
			check[i] = 10000;
		}

		int a, b;
		cin >> a >> b;

		check[a] = 0;
		que.push(a);

		while (que.empty() == false) {
			int now = que.front();
			que.pop();

			for (int i{ 0 }; i < road[now].size(); i++) {   //0부터임
				if (check[road[now][i]] > check[now] + 1) {   //방문하지 않앗을 경우 방을 큐에 추가
					que.push(road[now][i]);
					check[road[now][i]] = check[now] + 1;
				}
			}
		}
		cout << check[b] << "\n";
	}
}