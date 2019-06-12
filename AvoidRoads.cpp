#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long long dp[102][102];
vector<int> v(4);

void tokenize(string str) {
    int pos = 0;
	for (int i = 0; i < str.size(); i++) {
		int temp = 0;
		bool flag = false;
		while (i < str.size() && isdigit(str[i])) {
			temp = temp * 10 + (str[i] - '0'), i++;
			flag = true;
		}
		if (flag)
			v[pos++] = temp;
	}
}

class AvoidRoads {
    public:
    long long numWays(int width, int height, vector <string> bad) {
        set<pair<pair<int, int>, pair<int, int>>> s;
        for (int i = 0; i < bad.size(); i++) {
        	tokenize(bad[i]);
            	s.insert({{v[0], v[1]}, {v[2], v[3]}});
	    	s.insert({{v[2], v[3]}, {v[0], v[1]}});
        }
        dp[0][0] = 1;
        for (int i = 0; i <= width; i++)
            for (int j = 0; j <= height; j++) {
                int x1 = i + 1, y1 = j, x2 = i, y2 = j + 1;
                if (s.find({{i, j}, {x1, y1}}) == s.end())
                    dp[x1][y1] += dp[i][j];
                if (s.find({{i, j}, {x2, y2}}) == s.end())
                    dp[x2][y2] += dp[i][j];
            }
        return dp[width][height];
    }
};
