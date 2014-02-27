// @author WJMZBMR

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long long int64;

bool isPrime(int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		int p = n, q = n + 1;
		while (!isPrime(p))
			--p;
		while (!isPrime(q))
			++q;
		//p<=n<q
		//1/2-1/p + 1/(pq)*(n-p+1)
		int64 A = 0, B = 1LL * p * q * 2;
		A += 1LL * p * q;
		A -= 1LL * q * 2;
		A += (n - p + 1) * 2;
		int64 g = __gcd(A, B);
		A /= g, B /= g;
		cout << A << "/" << B << endl;
	}
}