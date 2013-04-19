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

class TheTriangleBothDivs{
public:
	string res, s;
	char str[15];
	int n;
	void fixit(string s) {
		int h = (s[0] - '0') * 10 + (s[1] - '0');
		int m = (s[3] - '0') * 10 + (s[4] - '0');
		int pl = (s[10] - '0');
		if (!(h < 24 && m < 60 && pl < 10))
			return;
		if (s[9] == '-' && !pl)
			return;
		if (s[9] == '-') pl = -pl;
		sprintf(str, "%02d:%02d", (h - pl + 24) % 24, m);
		string t = str;
		res = min(res, t);
	}
	void go(int v) {
		if (v == n)
			fixit(s);
		else if (s[v] >= '0' && s[v] <= '9')
			go(v + 1);
		else if (s[v] == '?') {
			if (v == 9) {
				s[v] = '+';
				go(v + 1);
				s[v] = '-';
				go(v + 1);
				s[v] = '?';
			}
			else {
				for (int i = 0; i < 10; i++) {
					s[v] = '0' + i;
					go(v + 1);
				}
				s[v] = '?';
			}
		}
		else go(v + 1);
	}
	string fix(string time){
		res = "99:99";
		s = time;
		n = time.size();
		go(0);
		return res;
	}
};


