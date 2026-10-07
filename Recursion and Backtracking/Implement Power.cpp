#include <iostream>
#include <vector>
using namespace std;

long double power (long double x, long long n) {
	if (n == 0)
		return 1.0L;

	long double half = power(x, n / 2);

	if (n % 2 == 0)
		return half * half;

	return x * half * half;
}

double myPow (double x, int n) {
	long long N = n;
	long double X = x;

	if (N < 0) {
		X = 1.0L / X;
		N = -N;
	}

	return (double)power(X, N);
}

int main() {
    long double x = -0.9999999968539456;
    long double n = -1669585506;
    
    cout << myPow(x, n);
}