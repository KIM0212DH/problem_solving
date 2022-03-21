#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int *ma = new int[n + 1];
		int *dp = new int[n + 1];

		for (int i{ 1 }; i < n + 1; i++) {
			int a;
			cin >> a;
			ma[i] = a;
		}
		int answer = 0;

		for (int i{ 1 }; i < n + 1; i++) {
			dp[i] = 1;
			for (int j{ 1 }; j < i; j++) {
				if (ma[j] < ma[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			answer = max(dp[i], answer);
		}

		cout << answer<<"\n";

	}
}