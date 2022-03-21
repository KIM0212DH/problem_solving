/*#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int main() {
	int T;
	int N;
	int X;
	cin >> T;
	while (T--) {
		cin >> N;
		//int X[100];
		deque<int> input;

		for (int i{ 0 }; i < N; i++) {
			cin >> X;
			input.push_back(X);
		}
		vector<int>test;

		int index{ 0 };
		while (!input.empty()) {
			if (test.empty()) {
				test.push_back(input.front());
				input.pop_front();

			}
			else if (input.front() != test.front()) {
				test.push_back(input.front());
				input.pop_front();
			}
			else if (input.front() == test.front()) {

				int match_count{ 0 };
				for (int i{ 0 }; i < input.size(); i++) {
					if (input.at(i) == test.at(i%test.size())) {
						match_count++;
					}
					else {
						break;
					}
				}


				for (int i{ 0 }; i < match_count; i++) {
					test.push_back(input.front());
					input.pop_front();

				}
			}

			int already_check{ 0 };
			for (int i{ 0 }; (i < input.size()); i++) {
				if (input.at(i) == test.at(i%test.size())) {
					already_check = 1;
				}
				else {
					already_check = 0;
					break;
				}
			}

			if (already_check)
				break;

		}

		for (int i{ 0 }; i < test.size(); i++) {
			cout << test[i] << " ";
		}
		cout << "\n";

	}
}*/


#include<iostream>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		int* signal = new int[N];
		int* prefix = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> signal[i];
		} 

		//computePrefixFunction()
		prefix[0] = 0;
		int k = 0;
		for (int i = 1; i < N; i++) {
			while (k > 0 && signal[i] != signal[k]) {	//일치하지 않는경우
				k = prefix[k - 1];
			}
			if (signal[i] == signal[k]) {		//일치하는 경우
				k = k + 1; 
			}
			prefix[i] = k;
		}

		for (int i = 0; i < N - prefix[N - 1]; i++) {
			cout << signal[i] << " ";
		}
		cout << '\n';
	}
}