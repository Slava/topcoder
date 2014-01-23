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
class CubeStickers{
public:
	string isPossible(vector<string> sticker){
map<string, int>M;
vector<int> v;
int mm = 0, num[70] = {0}, n = 0, d = 0;
		for (int i = 0; i < sticker.size(); i++) {
			string t = sticker[i];
			if (M.find(t) == M.end())
				M[t] = ++mm;
			v.push_back(M[t]);
		}
		sort (v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			num[v[i]]++;
		}
		n = (int)(unique (v.begin(), v.end()) - v.begin());
		printf("n=%d\n", n);for (int i =0 ; i < n; i++)printf("%d\n", v[i]);
		if (n >= 6) return "YES";
		for (int i = 0; i < 70; i++)
			if (num[i] >= 2) d++;
		printf("d= %d\n%d = d\n", d, n);
		if (n + d >= 6) return "YES";
		return "NO";
	}
};


