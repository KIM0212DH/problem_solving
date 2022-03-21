#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int** tri = new int*[n + 1];
		for (int i{ 1 }; i < n + 1; i++) {
			tri[i] = new int[i + 1];
		}

		for (int i{ 1 }; i < n + 1; i++) {
			for (int j{ 1 }; j <= i; j++) {
				cin >> tri[i][j];
			}
		}

		int** path = new int*[n + 1];
		for (int i{ 1 }; i < n + 1; i++) {
			path[i] = new int[i + 1];
		}

		

		path[1][1] = tri[1][1];

		for (int i{ 2 }; i < n + 1; i++) {

			path[i][1] = path[i - 1][1] + tri[i][1];

			for (int j{ 2 }; j < i; j++) {	

				path[i][j] = min(path[i - 1][j - 1], path[i - 1][j]) + tri[i][j];
			}

			path[i][i] = path[i - 1][i - 1] + tri[i][i];
		}

		int answer = path[n][1];

		for (int i{ 2 }; i < n + 1; i++) {
			answer = min(path[n][i], answer);
		}
		cout << answer << "\n";
	}
}
