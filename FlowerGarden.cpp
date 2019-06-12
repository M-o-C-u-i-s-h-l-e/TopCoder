// O(n ^ 3)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

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



// O(n ^ 2)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, arr[50][50];
vector<int> ans;
vector<pair<int, pair<int, int>>> v;
vector<bool> visited;

void sol(int i) {
	if (!visited[i]) {
		for (int j = 0; j < n; j++)
			if (arr[i][j] != i)
				sol(arr[i][j]);
		ans.push_back(v[i].first);
		visited[i] = true;
	}
}

class FlowerGarden {
	public:
    vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
    	n = height.size();
        v.resize(n+1);
	    visited.resize(n+1, false);
        for (int i = 0; i < n; i++) v[i].first = height[i];
        for (int i = 0; i < n; i++) v[i].second.first = bloom[i];
        for (int i = 0; i < n; i++) v[i].second.second = wilt[i];
        sort(v.begin(), v.end(), greater<pair<int, pair<int, int>>>());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = (!(v[i].second.first > v[j].second.second || v[i].second.second < v[j].second.first) && v[i].first > v[j].first) ? j : i;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                sol(i);
        return ans;
    }
};
