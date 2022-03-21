#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int T, X, Y;
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;

	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;

		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}

		if (x3 > x4) {
			swap(x3, x4);
			swap(y3, y4);
		}

		if (x1 == x2 && x3 == x4) {   //L1과 L2가 y축에 평행
			if (x1 != x3) {
				cout << "1" << "\n";
			}
			else if (x1 == x3) {
				if (y1 > y2) {
					swap(y1, y2);
				}
				if (y3 > y4) {
					swap(y3, y4);
				}
				if (y1 > y4 || y3 > y2) {
					cout << "1" << "\n";	//y축에 평행하면서 안만남
				}
				if (y1 == y4 || y3 == y2) {
					cout << "2" << "\n";	//y출에 평행하면서 한점에서 만남
				}
				if ((y1 <= y3 && y4 <= y2) || (y3 <= y1 && y2 <= y4)) {
					cout << "4" << "\n";		//포함됨
				}
				if ((y1 > y3 && y1 < y4 && y4 < y2) || (y3 > y1 && y3 < y2 && y2 < y4)) {
					cout << "3" << "\n";	//부분 겹침
				}
			}
		}
		else if (x1 == x2 && y3 == y4) {		//L1은 y축 평행, L2가 x축에 평행일때 
			X = x1;
			Y = y3;
			if ((min(y1, y2) <= Y && max(y1, y2) >= Y) && (X >= x3 && X <= x4)) {
				cout << "2" << "\n";
			}
			else {
				cout << "1" << "\n";
			}
		}
		else if (y1 == y2 && x3 == x4) {	//L1은 x축 평행, L2가 y축 평행
			X = x3;
			Y = y1;
			if ((X >= x1 && X <= x2) && (min(y3, y4) <= Y && Y <= max(y3, y4))) {
				cout << "2" << "\n";
			}
			else {
				cout << "1" << "\n";
			}
		}
		else if (y1 == y2 && y3 == y4) {
			if (y1 != y3) {
				cout << "1" << "\n";
			}
			else if (y1 == y3) {
				if (x1 > x4 || x3 > x2) {
					cout << "1" << "\n";
				}
				if (x1 == x4 || x3 == x2) {
					cout << "2" << "\n";
				}
				if ((x1 <= x3 && x4 <= x2) || (x3 <= x1 && x2 <= x4)) {
					cout << "4" << "\n";
				}
				if ((x1 > x3 && x1 < x4 && x4 < x2) || (x3 > x1 && x3 < x2 && x2 < x4)) {
					cout << "3" << "\n";
				}
			}
		}
	}
}