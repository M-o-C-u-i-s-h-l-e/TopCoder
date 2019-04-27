#include <bits/stdc++.h>
using namespace std;

class FlowerGarden {
	public:
    vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
    	int n = height.size();
        vector<int> v(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            int Max = 0, pos = -1;
            for (int j = 0; j < n; j++) {
                if (visited[j])	continue;
                bool flag = true;
                for (int k = 0; k < n; k++) {
                    if (visited[k])	continue;
                    bool block = !(bloom[j] > wilt[k] || bloom[k] > wilt[j]);
                    if (block && height[j] > height[k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag && height[j] > Max)
                    Max = height[j], pos = j;
            }
            v[i] = height[pos], visited[pos] = true;
        }
        return v;
    }
};
