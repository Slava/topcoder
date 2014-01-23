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

int prefix_function(string s, bool rev = 0) {
	vector<int> pr(s.size());
	int n = (int)s.size(), j = 0, k = s.find("$");
	if (rev)
		reverse(s.begin(), s.begin() + k),
		reverse(s.begin() + k + 1, s.end());
	for (int i = 1; i < n; i++) {
		while (j > 0 && s[j] != s[i])
			j = pr[j - 1];
		if (s[i] == s[j])
			j++;
		pr[i] = j;
	}
	return j;
}

class TemplateMatching{
public:
	string bestMatch(string text, string prefix, string suffix){
		int n = (int)text.size();
		string res; int mx = -1, prf = 0;
		for (int i = 0; i < n; i++)
			for (int j = 1; j + i <= n; j++) {
				string str = text.substr(i, j);
				int pr = prefix_function(prefix + "$" + str, 1),
					su = prefix_function(suffix + "$" + str), c = pr + su;
				if (c > mx)
					mx = c, res = str, prf = pr;
				else if (c == mx && prf < pr)
					res = str, prf = pr;
				else if (c == mx && prf == pr && res > str)
					res = str;
			}
		return res;
	}
};


