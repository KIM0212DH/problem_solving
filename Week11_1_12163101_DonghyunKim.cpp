#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>

/*
bool check_possible(string now, int *n) {

	for (int i{ 0 }; i < now.length(); i++) {
		int alphabet_to_idx{ 0 };
		if (now[i] == 'a') {
			alphabet_to_idx = 1;
		}
		else if (now[i] == 'b') {
			alphabet_to_idx = 2;
		}
		else if (now[i] == 'c') {
			alphabet_to_idx = 3;
		}
		else if (now[i] == 'd') {
			alphabet_to_idx = 4;
		}
		else if (now[i] == 'e') {
			alphabet_to_idx = 5;
		}
		else if (now[i] == 'f') {
			alphabet_to_idx = 6;
		}
		else if (now[i] == 'g') {
			alphabet_to_idx = 7;
		}
		else if (now[i] == 'h') {
			alphabet_to_idx = 8;
		}
		else if (now[i] == 'i') {
			alphabet_to_idx = 9;
		}
		else if (now[i] == 'j') {
			alphabet_to_idx = 10;
		}
		else if (now[i] == 'k') {
			alphabet_to_idx = 11;
		}
		else if (now[i] == 'l') {
			alphabet_to_idx = 12;
		}
		else if (now[i] == 'm') {
			alphabet_to_idx = 13;
		}
		else if (now[i] == 'n') {
			alphabet_to_idx = 14;
		}
		else if (now[i] == 'o') {
			alphabet_to_idx = 15;
		}
		else if (now[i] == 'p') {
			alphabet_to_idx = 16;
		}
		else if (now[i] == 'q') {
			alphabet_to_idx = 17;
		}
		else if (now[i] == 'r') {
			alphabet_to_idx = 18;
		}
		else if (now[i] == 's') {
			alphabet_to_idx = 19;
		}
		else if (now[i] == 't') {
			alphabet_to_idx = 20;
		}
		else if (now[i] == 'u') {
			alphabet_to_idx = 21;
		}
		else if (now[i] == 'v') {
			alphabet_to_idx = 22;
		}
		else if (now[i] == 'w') {
			alphabet_to_idx = 23;
		}
		else if (now[i] == 'x') {
			alphabet_to_idx = 24;
		}
		else if (now[i] == 'y') {
			alphabet_to_idx = 25;
		}
		else if (now[i] == 'z') {
			alphabet_to_idx = 26;
		}
		n[alphabet_to_idx]--;
		if (n[alphabet_to_idx] < 0) {
			return false;
		}
		else {
			continue;
		}
		return true;
	}
	return true;
}

int main() {
	queue<pair<string, int>> que;
	int n[27];	//���ĺ� a ~ z
	for (int i{ 1 }; i < 27; i++) {
		cin >> n[i];
	}

	int m;
	cin >> m;
	string *w = new string[m + 1];
	int *s = new int[m + 1];
	pair<string, int> *p = new pair<string, int>[m + 1];

	for (int i{ 1 }; i < m + 1; i++) {
		cin >> w[i] >> s[i];
		p[i] = make_pair(w[i], s[i]);
		que.push(p[i]);
	}

	int *check = new int[m + 1];

	for (int i{ 0 }; i < m + 1; i++) {
		check[i] = 0;
	}
	int j = 0;
	int temp_arr[27];
	copy(n, n + 27, temp_arr);

	while (que.empty() == false) {
		string now = que.front().first;
		if (check_possible(now, temp_arr)) {
			check[j] += que.front().second;
		}
		else {
			copy(n, n + 27, temp_arr);
			j++;
			check[j] += que.front().second;
		}
		que.pop();
	}

	int answer{ 0 };
	for (int i{ 0 }; i < m + 1; i++) {
		answer = max(answer, check[i]);
	}
	cout << answer;
}*/

using namespace std;

void solution(int *getScore, int *score, bool *t_f, int **restAlphabet, int **needAlphabet, int m, int answer) {
	getScore[0] = 0;	//���� �ܾ �ϳ��� ������ �ʾƼ� 0���� �ʱ�ȭ
	for (int i{ 1 }; i < m + 1; i++) {
		int status = 1 << (i - 1);	//�ܾ� ���ڰ� �ϳ��� �þ������ ó���ؾ��� �迭 ������ ���ڰ� 2�辿 �þ
		for (int j{ 0 }; j < status; j++) {
			if (t_f[j] = false) {	//���� ���°� ������ ���ϴ� ����
				continue;
			}
			bool flag = false;	//���� �� ������
			for (int k{ 1 }; k < 27; k++) {
				if (restAlphabet[j][k] < needAlphabet[i][k]) {//���� �ܾ ����� ���� �ʿ��� ���ĺ� ������ �����ִ� ���ĺ� �������� ������, �� ���ĺ� ������ ���ڸ� ���
					flag = true;
				}
			}
			if (flag == true) {
				continue;
			}

			for (int k{ 1 }; k < 27; k++) {	//����� �ִ� ���
				restAlphabet[j + status][k] = restAlphabet[j][k] - needAlphabet[i][k];
			}
			getScore[j + status] = getScore[j] + score[i];
			answer = max(answer, getScore[j + status]);
		}
	}



}


int main() {
	int n[27];
	for (int i{ 1 }; i < 27; i++) {
		cin >> n[i];
	}
	int m;
	cin >> m;
	int pow_m = pow(2, m);

	int *score = new int[m + 1];
	bool *t_f = new bool[pow_m];

	int **needAlphabet = new int*[m + 1];
	for (int i{ 1 }; i < m + 1; i++) {
		needAlphabet[i] = new int[27];
	}

	int **restAlphabet = new int*[pow_m + 1];
	for (int i{ 0 }; i < pow_m + 1; i++) {
		restAlphabet[i] = new int[27];
	}

	int answer{ 0 };
	string word;
	int *getScore = new int[pow_m];

	for (int i{ 1 }; i < 27; i++) {
		restAlphabet[0][i] = n[i];		//�ʱ� �־��� ���ĺ� ����
	}
	for (int i{ 1 }; i < m + 1; i++) {
		cin >> word >> score[i];
		for (int j{ 1 }; j < word.length() + 1; j++) {
			needAlphabet[i][word[j] - 'a' + 1] += 1;	//banana, bane, nas ���� �ʿ��� �� ���ĺ��� ���� ����
		}
	}
	solution(getScore, score, t_f, restAlphabet, needAlphabet, m, answer);
	cout << answer;


}