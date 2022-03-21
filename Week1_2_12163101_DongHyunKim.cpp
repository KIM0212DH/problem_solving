/*
#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

int T{ 0 };	//�ݺ��� test Ƚ��
int C{ 0 };	//���� ����
int main() {
	cin >> T;

	int n;	//���� ��ȣ 1 �Ǵ� 2
	int bn; //��� ��ȣ

	vector<int>::iterator iter;
	while (T--) {
		vector<int>blocks = {};
		int min{ 1000 };
		int max{ 0 };

		cin >> C;

		while (C--) {
			cin >> n;
			switch (n) {
			case 1:
				cin >> bn;
				blocks.push_back(bn);

				for (iter = blocks.begin(); iter != blocks.end(); iter++) {
					if (min >= *iter)
						min = *iter;
					if (max <= *iter)
						max = *iter;
				}
				cout << min << " " << max << "\n";
				break;

			case 2:
				if (blocks.size() == 0)
					break;
				if (blocks.back() == min || blocks.back() == max) {
					blocks.pop_back();
					min = 1000;
					max = 0;
					for (iter = blocks.begin(); iter != blocks.end(); iter++) {
						if (min >= *iter)
							min = *iter;
						if (max <= *iter)
							max = *iter;
					}
				}
				else
					blocks.pop_back();

				break;
			}

		}

	}
}
*/

#include<iostream>
#include<stack>
using namespace std;

int t;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		stack<int> minStack;
		stack<int> maxStack;
		int n;
		cin >> n;
		while (n--) {
			int q;
			cin >> q;

			//�ױ�
			if (q == 1) {
				int num;
				cin >> num;

				//������ ����� ���
				if (minStack.empty()) {
					maxStack.push(num);
					minStack.push(num);
				}
				else {
					//�ִ밪 ����
					if (num > maxStack.top()) {
						maxStack.push(num);
					}
					else {
						maxStack.push(maxStack.top());
					}

					//�ּҰ� ����
					if (num < minStack.top()) {
						minStack.push(num);
					}
					else {
						minStack.push(minStack.top());
					}
				}

				cout << minStack.top() << " " << maxStack.top() << "\n";
			}

			//����
			else {
				if (!minStack.empty()) {
					minStack.pop();
					maxStack.pop();
				}
			}
		}
	}
	return 0;
}

