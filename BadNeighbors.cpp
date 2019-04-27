#include <bits/stdc++.h>
using namespace std;

int func(int start, int end, vector<int> &donations) {
	int a = 0, b = 0, c = 0;
	for (int i = start; i < end; i++) {
		int Max = max(a, b);
		a = Max, b = c, c = Max + donations[i];
	}
	return max(a, max(b, c));
}

class BadNeighbors {
	public:
	int maxDonations(vector <int> donations) {
		int t1 = func(0, donations.size()-1, donations);
		int t2 = func(1, donations.size(), donations);
		return max(t1, t2);
	}
};
