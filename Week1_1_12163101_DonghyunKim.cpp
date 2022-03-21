#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <string>
#include <array>

using namespace std;
#define ARRMAX	100
#define STRINGMAX 1000

int T{ 0 };				//반복 횟수
int K{ 0 };
string S;
int main() {
	cin >> T;	//테스트 횟수 입력

	while (T--) {
		//T번 만큼 테스트


		cin >> S;	//문자열 S 입력
		//int len = sizeof(S);

		cin >> K;	//배열의 행 K 입력

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
		//반복 종료후 배열 출력
	}
}



//강의 이전 코드
/*#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <array>

using namespace std;
#define ARRMAX	100
#define STRINGMAX 1000

int T{ 0 };				//반복 횟수
int K{ 0 };
int main() {
	cin >> T;	//테스트 횟수 입력

	while (T--) {
		//T번 만큼 테스트

		char arr[ARRMAX][ARRMAX] = {};		//최대 100 x 100 의 배열생성
		char S[STRINGMAX] = {};


		cin >> S;	//문자열 S 입력
		int len = strlen(S);
		if (len > STRINGMAX)
			return 0;

		cin >> K;	//배열의 행 K 입력
		if (K < 1) {
			return 0;
		}
		if (len / K > ARRMAX) {
			return 0;
		}

		//int dxs[4] = { 1,0,-1,0 };	//{동,남,서,북}
		//int dys[4] = { 0,1,0,-1 };

		int cur_x = 0;
		int cur_y = 0;

		int dx{ 0 }, dy{ 1 };

		for (int i{ 0 }; i < len; i++) {	//아래로 배열에 추가해주면서 K%i가 K-1이면 오른쪽으로 이동, 그리고 위아래 방향 바꿈

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
		//반복 종료후 배열 출력
	}
}
*/
