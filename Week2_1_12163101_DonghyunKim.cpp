#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T{ 0 };
	string S;

	cin >> T;

	while (T--) {
		int N{ 0 };	//친구수	
		int M{ 0 };	//전체 문장의 단어수

		cin >> N >> M;
		queue<string> word[20] = {};

		string* pstring = new string[M];

		for (int i{ 0 }; i < M; i++) {
			cin >> pstring[i];
		}

		for (int i{ 0 }; i < N; i++) {
			int K{ 0 }; //각 친구들이 필기한 단어수
			cin >> K;
			for (int j{ 0 }; j < K; j++) {
				cin >> S;
				word[i].push(S);
			}
		}
		int answer;
		for (int i{ 0 }; i < M; i++) {
			answer = 0;
			for (int j{ 0 }; j < N; j++) {
				if (pstring[i] == word[j].front()) {
					word[j].pop();
					answer = 1;
					break;
				}
			}
			if (answer == 0) {
				break;
			}
		}

		cout << answer << "\n";

		delete[] pstring;

		/*
		char** text = new char*[50];
		for (int i = 0; i < 50; i++)
			text[i] = new char[100];

		for (int i{ 0 }; i < 50; i++) {
			for (int j{ 0 }; j < 100; j++) {
				cout << text[i][j] << " ";
			}
			cout << "\n";
		}


		for (int i = 0; i < 50; i++) {
			delete[] text[i];
		}
		delete[] text;



	}*/

	}
}