#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T{ 0 };
	cin >> T;


	while (T--) {
		int N{ 0 };
		cin >> N;

		int *inha_value = new int[N];
		int *biryong_value = new int[N];
		pair<int, int> resourceSum[10000] = {};
		for (int i{ 0 }; i < N; i++) {
			cin >> inha_value[i] >> biryong_value[i];
			resourceSum[i] = make_pair(inha_value[i] + biryong_value[i], i);		//중요
		}

		sort(resourceSum, resourceSum + N, greater<>());//내림차순 정렬		중요
		int answer = 0;
		int flag = 1;

		for (int i{ 0 }; i < N; i++) {
			if (flag == 1) {
				answer += inha_value[resourceSum[i].second];		//인하먼저
				flag = 0;
			}
			else if (flag == 0) {
				answer -= biryong_value[resourceSum[i].second];		//번갈아가면서
				flag = 1;
			}
		}
		cout << answer << "\n";

		delete[] inha_value;
		delete[] biryong_value;
	}
}