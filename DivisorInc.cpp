#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class DivisorInc {
    public:
    int countOperations(int N, int M) {
        vector<int> v(100001, INT_MAX);
        v[N] = 0;
        for (int i = N; i <= M; i++) {
            if (v[i] != INT_MAX) {
                for (int j = 2; j <= sqrt(i); j++) {
                    if (i % j == 0) {
                        int temp = i + j;
                        if (temp <= M)
                            v[temp] = min(v[temp], v[i]+1);
                        temp = i + i / j;
                        if (temp <= M)
                            v[temp] = min(v[temp], v[i]+1);
                    }
                }
            }
        }
        return (v[M] == INT_MAX) ? -1 : v[M];
    }
};

/*class DivisorInc {
   	public:
    int countOperations(int N, int M) {
        queue<int> q;
        int ret = -1;
        vector<int> t(100001, -1);
        t[N] = 0;
        q.push(N);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == M) {
                ret = t[cur];
                break;
            }
            for (int i = 2; i <= sqrt(cur); i++) {
                if (cur % i == 0) {
                    if (cur + i <= M && t[cur + i] == -1) {
                        t[cur + i] = t[cur] + 1;
                        q.push(cur + i);
                    }
                    if (cur + cur / i <= M && t[cur + cur / i] == -1) {
                        t[cur + cur / i] = t[cur] + 1;
                        q.push(cur + cur / i);
                    }
                }
            }
        }
        return ret;
    }
};*/
