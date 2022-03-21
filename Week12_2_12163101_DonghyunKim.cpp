#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<pair<int, int>> s_d{};	//new pair<int,int> room[n+1]·Î ÇØµµµÊ
		vector<pair<int, int>> answer{};	

		for (int i{ 0 }; i < n; i++) {
			int a, b;
			cin >> a >> b;
			s_d.push_back({ a,b });
		}
		sort(s_d.begin(), s_d.end(), compare);

		int d_min{ s_d[0].second };

		answer.push_back({ s_d[0].first,s_d[0].second });
		for (int i{ 1 }; i < n; i++) {
			if (d_min > s_d[i].second) {
				answer.push_back({ s_d[i].first,s_d[i].second });	//int answercount++ÇØµµµÊ
				d_min = s_d[i].second;
			}
		}
		cout << answer.size() << "\n";


	}


}