/*#include <iostream>
#include <string>
#include <vector>
using namespace std;

void calDistance(int*, int, int);

int main() {
	int N;
	int M;

	cin >> N >> M;

		vector<int> house;
		int temp;
		for (int i{ 0 }; i < 5; i++) {
			cin >> temp;
			house.push_back(temp);
		}

		for (int i{ 0 }; i < house.size(); i++) {
			cout << house[i] << " ";
		}

	int* house = new int[N];
	for (int i{ 0 }; i < N; i++) {
		cin >> house[i];
	}
	int* resident = new int[M];
	resident[0] = house[0];	//첫번째 주민은 첫번째 집
	resident[M - 1] = house[N - 1];	//마지막 주민은 마지막 집

	int incident = 0;

	calDistance(house, house[0], house[N - 1]);
}

void calDistance(int* house, int houseStart, int houseEnd) {
	int min_gap{ 100000 };
	int nextHouse;
	for (int i{ 0 }; i < (_msize(house) / sizeof(int)); i++) {
		if (min_gap > abs(house[i] - ((houseStart + houseEnd) / 2))) {
			nextHouse = house[i];
			min_gap = abs(house[i] - ((houseStart + houseEnd) / 2));
		}[[[[[[[[[[[]]]]]]]]]]]
	}

	calDistance(house, houseStart, nextHouse);
	calDistance(house, nextHouse, houseEnd);


}

void setHouse(int* house, int left, int right, int* resident) {
	int house_avg = (house[right] + house[left]) / 2;
	for (int i{ 0 }; i < (_msize(house) / sizeof(int)); i++) {

	}
}*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int M;
	vector<int> house;

	cin >> N >> M;

	for (int i{ 0 }; i < N; i++) {
		int X;
		cin >> X;
		house.push_back(X);
	}
	int min_distance{ 0 };

	int left = house.front();
	int right = house.back();


	while (left <= right) {

		int mid = (left + right) / 2;
		int start_idx{ 0 };
		int resident_count{ 1 };
		for (int i{ 0 }; i < N; i++) {
			if (house[i] - house[start_idx] >= mid) {
				start_idx = i;
				resident_count++;
			}

		}
		if (resident_count >= M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

		if (min_distance < mid && resident_count >= M) {
			min_distance = mid;
		}
	}

	cout << min_distance;

}