#include <bits/stdc++.h>
using namespace std;

class PrimePolynom {
	public:
	int reveal(int A, int B, int C) {
        for (int i = 0; i <= 10000; i++) {
            long long n = A * i * i + B * i + C;
            if (n < 0)  return i;
            for (int j = 2; j <= sqrt(n); j++) {
                if (n % j == 0) {
                    return i;
                }
            }
        }
        return 0;
    }
};
