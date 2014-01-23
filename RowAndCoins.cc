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

int win[1<<14][2], n, add[15][15];
string s;

int go(int m, int h) {
	int &res = win[m][h];
	if (res + 1)
		return res;
	res = 0;
	int cnt = 0, p, a[14] = {0};
	for (int i = 0; i < n; i++) {
		if (m & (1 << i))
			cnt++;
		else
			p = i;
		a[i] = cnt;
	}
	if (cnt == n - 1) {
	//	printf("p = %d, h = %d, s[p] = %c\n", p, h, s[p]);
		return res = (s[p] == 'A') ^ h;
	}
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (a[i] == a[j] && 
			(m | add[i][j]) != (1 << n) - 1)
				res |= 1 ^ go(m | add[i][j], h ^ 1);
	return res;
}

class RowAndCoins{
public:
	string getWinner(string s){
		::s = s;
		n = (int)s.size();
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++) {
				int M = 0;
				for (int k = i; k <= j; k++)
					M |= 1 << k;
				add[i][j] = M;
			}
		memset(win, -1, sizeof win);
		return go(0, 0) ? "Alice" : "Bob";
	}
};


