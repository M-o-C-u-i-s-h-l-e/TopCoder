#include <bits/stc++.h>
using namespace std;

int Count(int n, int start) {
    int res = 0;
    for (int i = start; i <= sqrt(n); i++)
        if (n % i == 0)
            res += Count(n/i, i) + 1;
    return res;
}

class Refactoring {
    public:
    int refactor(int n) {
        return Count(n, 2);
    }
};
