#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*
int T;
int A, B, x, y;
int checkGCD(int A, int B);
int main() {
   cin >> T;
   while (T--) {
	  int answer{ 0 };
	  cin >> A >> B >> x >> y;
	  answer = checkGCD(A, B);
	  int cost{ 1000000 };

	  int tempA{ A }, tempB{ B };
	  int tempCostA{ cost }, tempCostB{ cost };

	  for (int i{ x }; i < 1000 && tempA <= 1000000 && tempB <= 1000000; i = i + x) {
		 tempA++, tempB++;
		 if (checkGCD(tempA, tempB) >= answer && (i < cost)) {
			answer = checkGCD(tempA, tempB);
			cost = i;
		 }
	  }

	  tempA = A, tempB = B;
	  for (int i{ y }; i < 1000 && tempA > 0 && tempB > 0; i = i + y) {
		 tempA--, tempB--;
		 if (checkGCD(tempA, tempB) >= answer && (i < cost)) {
			answer = checkGCD(tempA, tempB);
			cost = i;
		 }
	  }

	  cout << answer << " " << cost << "\n";
   }

}

int checkGCD(int A, int B) {
   int temp;
   if (A < B) {
	  temp = A;
	  A = B;
	  B = temp;
   }
   if (A == B) {
	  return A;
   }
   else if (B == 0) {
	  return A;
   }
   else {
	  return checkGCD(B, A%B);
   }
}*/

int main() {
	int T, A, B, x, y, g, cost;


	cin >> T;

	while (T--) {
		cin >> A >> B >> x >> y;

		g = A - B;
		if (g < 0)
			g = -g;

		cost = (g - (B % g)) * x;	//숙련도 올림

		if (min(A, B) >= g) {
			cost = min(cost, (B % g) * y);	//(B % g) * y는 숙련도 내림
		}

		cout << g << " " << cost << "\n";
	}
}