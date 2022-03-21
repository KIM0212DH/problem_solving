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
			resourceSum[i] = make_pair(inha_value[i] + biryong_value[i], i);		//�߿�
		}

		sort(resourceSum, resourceSum + N, greater<>());//�������� ����		�߿�
		int answer = 0;
		int flag = 1;

		for (int i{ 0 }; i < N; i++) {
			if (flag == 1) {
				answer += inha_value[resourceSum[i].second];		//���ϸ���
				flag = 0;
			}
			else if (flag == 0) {
				answer -= biryong_value[resourceSum[i].second];		//�����ư��鼭
				flag = 1;
			}
		}
		cout << answer << "\n";

		delete[] inha_value;
		delete[] biryong_value;
	}
}