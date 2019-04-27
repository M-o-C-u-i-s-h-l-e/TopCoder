#include <bits/stdc++.h>
using namespace std;

class ZigZag {
    public:
	int longestZigZag(vector <int> sequence) {
        if (sequence.size() == 1)	return 1;
        int cur = (sequence[0] < sequence[1]) ? 1 : 0, Count = 1;
        for (int i = 1; i < sequence.size(); i++) {
            if (cur && sequence[i] > sequence[i-1])
                Count++, cur = 0;
            else if (!cur && sequence[i] < sequence[i-1])
                Count++, cur = 1;
        }
        return Count;
    }
};
