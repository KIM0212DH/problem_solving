#include <iostream>
#include <string>

using namespace std;

struct paperInfo {
	int redNumber{ 0 };
	int redSize{ 0 };
	int blueNumber{ 0 };
	int blueSize{ 0 };
};

paperInfo solution(int x, int y, int size, char**paper) {
	paperInfo ret;
	if (size == 1) {
		if (paper[x][y] == 'R') {
			ret.redNumber = ret.redSize = 1;
		}
		else {
			ret.blueNumber = ret.blueSize = 1;
		}
		return ret;
	}
	paperInfo status[5];
	status[1] = solution(x, y, size / 2, paper);
	status[2] = solution(x + size / 2, y, size / 2, paper);
	status[3] = solution(x, y + size / 2, size / 2, paper);
	status[4] = solution(x + size / 2, y + size / 2, size / 2, paper);

	for (int i{ 1 }; i < 5; i++) {
		ret.redNumber += status[i].redNumber;
		ret.redSize += status[i].redSize;
		ret.blueNumber += status[i].blueNumber;
		ret.blueSize += status[i].blueSize;
	}
	if (ret.redNumber == 0) {
		ret.blueNumber = 1;
	}
	if (ret.blueNumber == 0) {
		ret.redNumber = 1;
	}
	return ret;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		char **paper = new char*[n];
		for (int i{ 0 }; i < n; i++) {
			paper[i] = new char[n];
		}

		for (int i{ 0 }; i < n; i++) {
			for (int j{ 0 }; j < n; j++) {
				cin >> paper[i][j];
			}
		}

		paperInfo answer = solution(0, 0, n, paper);

		cout << answer.redNumber << " " << answer.redSize << " " << answer.blueNumber << " " << answer.blueSize << "\n";

	}
}