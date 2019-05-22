#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<int> v(100001, INT_MAX);
	v[n] = 0;
	for (int i = n; i <= m; i++) {
		if (v[i] != INT_MAX) {
			for (int j = 2; j <= sqrt(i); j++) {
				if (i%j == 0) {
					int temp = i + j;
					if (temp <= m)
						v[temp] = min(v[temp], v[i]+1);
					temp = i + i / j;
					if (temp <= m)
						v[temp] = min(v[temp], v[i]+1);
				}
			}
		}
	}
	(v[m] == INT_MAX) ? cout << -1 << endl : cout << v[m] << endl;
}
