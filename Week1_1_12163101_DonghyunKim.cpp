#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <string>
#include <array>

using namespace std;
#define ARRMAX	100
#define STRINGMAX 1000

int T{ 0 };				//�ݺ� Ƚ��
int K{ 0 };
string S;
int main() {
	cin >> T;	//�׽�Ʈ Ƚ�� �Է�

	while (T--) {
		//T�� ��ŭ �׽�Ʈ


		cin >> S;	//���ڿ� S �Է�
		//int len = sizeof(S);

		cin >> K;	//�迭�� �� K �Է�

		int len = S.size();
		for (int i{ 0 }; i < K; i++) {
			for (int j{ 0 };; j = j + 2 * K) {
				if (j + i >= len)
					break;
				cout << S[j + i];
				if (j + 2 * K - i - 1 >= len)
					break;
				cout << S[j + 2 * K - i - 1];
			}
		}
		//int cnt{ 0 };
		cout << "\n";
		//�ݺ� ������ �迭 ���
	}
}



//���� ���� �ڵ�
/*#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <array>

using namespace std;
#define ARRMAX	100
#define STRINGMAX 1000

int T{ 0 };				//�ݺ� Ƚ��
int K{ 0 };
int main() {
	cin >> T;	//�׽�Ʈ Ƚ�� �Է�

	while (T--) {
		//T�� ��ŭ �׽�Ʈ

		char arr[ARRMAX][ARRMAX] = {};		//�ִ� 100 x 100 �� �迭����
		char S[STRINGMAX] = {};


		cin >> S;	//���ڿ� S �Է�
		int len = strlen(S);
		if (len > STRINGMAX)
			return 0;

		cin >> K;	//�迭�� �� K �Է�
		if (K < 1) {
			return 0;
		}
		if (len / K > ARRMAX) {
			return 0;
		}

		//int dxs[4] = { 1,0,-1,0 };	//{��,��,��,��}
		//int dys[4] = { 0,1,0,-1 };

		int cur_x = 0;
		int cur_y = 0;

		int dx{ 0 }, dy{ 1 };

		for (int i{ 0 }; i < len; i++) {	//�Ʒ��� �迭�� �߰����ָ鼭 K%i�� K-1�̸� ���������� �̵�, �׸��� ���Ʒ� ���� �ٲ�

			arr[cur_x][cur_y] = S[i];


			if (i % K == K - 1) {
				dx = 1;
				cur_x = cur_x + dx;
				dy = -dy;
			}
			else {
				dx = 0;
				cur_x = cur_x + dx;
				cur_y = cur_y + dy;
			}
		}
		//int cnt{ 0 };
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (arr[i][j] == '\0')
					break;
				cout << arr[i][j];
				//cnt++;
				//if (cnt > len)
				//	break;
			}
		}
		cout << "\n";
		//�ݺ� ������ �迭 ���
	}
}
*/
