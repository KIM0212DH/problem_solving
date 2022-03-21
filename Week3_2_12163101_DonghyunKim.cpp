/*#include <iostream>
#include <vector>
#include <array>
#include <stdlib.h>
using namespace std;

struct roadInfo {
	int neighbor;
	int distance;
};
int answer{ 0 };

vector<roadInfo> house[2000];
bool visitedHouse[2000];

int treeSearch(int u) {
	int maxDistance{ 0 };
	int secondMaxDistance{ 0 };
	int tempDistance;

	visitedHouse[u] = true;
	for (unsigned int i{ 0 }; i < house[u].size(); i++) {
		if (visitedHouse[house[u][i].neighbor] == false) {
			tempDistance = treeSearch(house[u][i].neighbor) + house[u][i].distance;
			if (tempDistance > maxDistance) {
				swap(tempDistance, maxDistance);
			}
			if (tempDistance > secondMaxDistance) {
				swap(tempDistance, secondMaxDistance);
			}
		}
	}
	answer = max(answer, maxDistance + secondMaxDistance);
	return maxDistance;
}


int main() {
	int T{ 0 };
	int N{ 0 };
	int u, v, d;

	cin >> T;
	while (T--) {
		cin >> N;
		

		for (int i{ 0 }; i < N - 1; i++) {
			cin >> u >> v >> d;
			house[u].push_back({ v,d });
			house[v].push_back({ u,d });
		}
		answer = 0;
		treeSearch(1);
		cout << answer << "\n";
		for (unsigned int i{ 0 }; i < 2000; i++) {
			house[i].clear();
			visitedHouse[i] = 0;
		}
	}

}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct roadInfo {
	int neighbor, distance;
};

int t, answer;

//u�� root�� Ʈ���� ���� �˻�
int treeSearch(int u, vector<roadInfo>* house, bool* visitedHouse) {
	//��� u�� �� �ڽ� ���� ����� leaf ���
	int maxDistance = 0, secondMaxDistance = 0;
	//��� u���� �Ÿ��� �� ���� ū 2���� ���� max, second�� ����
	int tempDistance;

	visitedHouse[u] = true;
	for (int i = 0; i < house[u].size(); i++) {
		//������ �湮�� �� ���ٸ�		
		if (visitedHouse[house[u][i].neighbor] == false) {
			tempDistance = treeSearch(house[u][i].neighbor, house, visitedHouse) + house[u][i].distance;
			if (tempDistance > maxDistance) {
				swap(tempDistance, maxDistance);
			}
			if (tempDistance > secondMaxDistance) {
				swap(tempDistance, secondMaxDistance);
			}
		}
	}

	answer = max(answer, maxDistance + secondMaxDistance);

	return maxDistance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n; // �� ����
		cin >> n;
		vector<roadInfo>* house = new vector<roadInfo>[n + 1];
		bool* visitedHouse = new bool[n + 1]{ false };
		answer = 0;
		for (int i = 1; i < n; i++) {		//���� ���� ��ŭ �Է�
			int u, v, d;
			cin >> u >> v >> d;
			house[u].push_back({ v, d });
			house[v].push_back({ u, d });
		}


		treeSearch(1, house, visitedHouse);
		cout << answer << "\n";
	}
}