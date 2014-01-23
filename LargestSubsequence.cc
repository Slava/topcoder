// imslavko
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

#define pb push_back
#define bit(x,y) (((x)>>(y))&1)

/* START */
class LargestSubsequence{
public:
	string getLargest(string s){
		int n = (int)s.size();
		string ans;
		for (int i = 0; i < n; i++) {
			int j = i;
			for (int k = i; k < n; k++)
				if (s[k] > s[j])
					j = k;
			ans.pb(s[j]);
			i = j;
		}
		return ans;
	}
};


