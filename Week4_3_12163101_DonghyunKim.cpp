#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int T;
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
	double a1, b1, a2, b2;
	double X, Y;

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
		else if (x3 == x4) {		//L2가 y축에 평행
			a1 = (y2 - y1) / (x2 - x1);
			b1 = y1 - a1 * x1;
			Y = a1 * x3 + b1;

			if ((min(y1, y2) <= Y && Y <= max(y1, y2)) && (min(y3, y4) <= Y && Y <= max(y3, y4)) && (x1 <= x3 && x3 <= x2)) {
				cout << "2" << "\n";
			}

			else {
				cout << "1" << "\n";
			}
		}
		else if (x1 == x2) {		//L1이 y축에 평행
			a2 = (y4 - y3) / (x4 - x3);
			b2 = y3 - a2 * x3;
			Y = a2 * x1 + b2;

			if ((min(y3, y4) <= Y && Y <= max(y3, y4)) && (min(y1, y2) <= Y && Y <= max(y1, y2)) && (x3 <= x1 && x1 <= x4)) {
				cout << "2" << "\n";
			}

			else {
				cout << "1" << "\n";
			}
		}
		else {
			a1 = (y2 - y1) / (x2 - x1);
			b1 = y1 - a1 * x1;
			a2 = (y4 - y3) / (x4 - x3);
			b2 = y3 - a2 * x3;

			if (a1 == a2 && b1 == b2) {	//교점이 무한개인 경우 기울기 같고 y절편 같다

				if (x1 > x4 || x3 > x2) {		//안만남 
					cout << "1" << "\n";
				}

				if (x1 == x4 || x3 == x2) {		//한점에서 만남
					cout << "2" << "\n";
				}

				if ((x1 <= x3 && x4 <= x2) || (x3 <= x1 && x2 <= x4)) {		//포함관계
					cout << "4" << "\n";
				}

				if ((x1 > x3 && x1 < x4 && x4 < x2) || (x3 > x1 && x3 < x2 && x2 < x4)) {
					cout << "3" << "\n";		//일부 겹침
				}
			}

			else if (a1 == a2 && b1 != b2) {	//기울기 같은데 y절편 다름. 안만남
				cout << "1" << "\n";
			}

			else {		//교점이 한개인경우
				X = (b2 - b1) / (a1 - a2);

				if ((x1 <= X && X <= x2) && (x3 <= X && X <= x4)) {
					cout << "2" << "\n";
				}

				else {
					cout << "1" << "\n";
				}
			}
		}

	}
}