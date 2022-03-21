#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

struct point_info {
	int x, y;
};

int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dy[8] = { 1,-1,0,1,-1,0,1,-1 };

set<point_info> candidate;

int CandidateCheckFunc() {
	int ret = 0;
	
	for (point_info point = candidate.begin; point < candidate.size(); i++) {
		check[point.x][point.y][1].clear();
	}
}

void aroundCandidateFunc(int x, int y) {
	for (int i{ 1 }; i < 9; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (grid[X][Y] == 0) {
			candidate.insert(point_info({ X,Y }));
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<vector<vector<int>>> check(n + 1, vector<vector<int>>(n + 1, vector<int>(2)));


		int **grid = new int*[n + 1];
		for (int i{ 0 }; i < n + 1; i++) {
			grid[i] = new int[n + 1];
			memset(grid[i], 0, sizeof(int)*(n + 1));
		}

		grid[n / 2][n / 2] = grid[n / 2 + 1][n / 2 + 1] = 1;
		grid[n / 2 + 1][n + 2] = grid[n / 2][n / 2 + 1] = 2;

		for (int i{ 0 }; i < 2; i++) {
			for (int j{ 0 }; j < 2; j++) {
				aroundCandidateFunc(n / 2 + i, n / 2 + j);
			}
		}

		int turn = 1;

		while (q--) {
			int x, y;
			cin >> x >> y;
			int flag = CandidateCheckFunc();

			if (flag & turn == 0) {
				turn = flag;
			}
			if (grid[x][y] != 0) {
				continue;
			}
			if (check[x][y][turn].empty() == true) {
				continue;
			}
			for (int k{ 1 }; k < check[x][y][turn].size(); k++) {
				int i = check[x][y][turn][k];
				for (int j{ 1 }; j < n + 1; j++) {
					if (grid[x + dx[i] * j][y + dy[i] * j] == turn) {
						break;
					}
					grid[x + dx[i] * j][y + dy[i] * j] = turn;
				}
			}
			grid[x][y] = turn;
			if (turn == 1) {
				turn = 2;
			}
			else {
				turn = 1;
			}
			candidate.erase(point_info({ x, y }));
			aroundCandidateFunc(x, y);
		}

		int ansCheck = 0;
		for (int i{ 1 }; i < n + 1; i++) {
			for (int j{ 1 }; j < n + 1; j++) {
				if (grid[i][j] == 1) {
					ansCheck += 1;
				}
				else if (grid[i][j] == 2) {
					ansCheck -= 1;
				}
			}
		}
		if (ansCheck > 0) {
			cout << "2" << endl;
		}
		else if (ansCheck < 0) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
}