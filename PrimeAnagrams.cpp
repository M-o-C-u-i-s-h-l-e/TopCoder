#include <bits/stdc++.h>
using namespace std;

int toInt(string str) {
    stringstream ss(str);
    int res;
    ss >> res;
    return res;
}

class PrimeAnagrams {
    public:
    vector<int> primes(string anagram) {
        vector<bool> p(1000001, true);
        p[0] = p[1] = false;
        for (int i = 2; i <= sqrt(1000000); i++)
            if (p[i])
            	for (int j = i*i; j <= 1000000; j+=i)
            		p[j] = false;
		int Min = INT_MAX;
    	vector<int> v;
        sort(anagram.begin(), anagram.end());
        do {
            if (anagram[0] == '0')
                continue;
           	for (int i = 0; i < anagram.size()-2; i++) {
                if (anagram[i+1] == '0')
                    continue;
                for (int j = i+1; j < anagram.size()-1; j++) {
                    if (anagram[j+1] == '0')
                        continue;
                    vector<int> t(3);
                    t[0] = toInt(anagram.substr(0, i+1));
                    t[1] = toInt(anagram.substr(i+1, j-i));
                    t[2] = toInt(anagram.substr(j+1));
                    if (p[t[0]] && p[t[1]] && p[t[2]])
                    	if (Min > t[0] * t[1] * t[2]) {
                        	Min = t[0] * t[1] * t[2];
                        	v = t;
                        }
                }
          	}
        } while (next_permutation(anagram.begin(), anagram.end()));
        sort(v.begin(), v.end());
        return v;
    }
};
