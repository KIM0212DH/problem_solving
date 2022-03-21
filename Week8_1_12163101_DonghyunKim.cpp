#include <iostream>
#include <math.h>
#include <string>

using namespace std;

static long long x, n, m;

pair<long long, long long> GeoSeries(long long x, long long n) {
	if (n == 1) {
		return { x % m,x % m };
	}

	pair<long long, long long> half = GeoSeries(x, n / 2);
	long long exp = half.first;
	long long sum = half.second;

	if (n % 2 == 0) {
		return { (exp * exp) % m, ((1 + exp) * sum) % m };
	}
	else {
		return { (x * exp * exp) % m, (x + x * (1 + exp) * sum) % m };
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> x >> n >> m;

		pair<long long, long long> answer = GeoSeries(x, n);

		cout << answer.second << "\n";
	}
}