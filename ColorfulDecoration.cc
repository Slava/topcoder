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
class ColorfulDecoration{
public:
	vector<int>x[2], y[2];
	int n, N, g[150][150];
	bool no(int x, int y, int X, int Y, int l) {
		return abs(x - X) < l && abs(Y - y) < l;
	}
	bool go(int len) {
		memset(g, 0, sizeof g);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j)
			for (int k = 0; k < 2; k++) for (int m = 0; m < 2; m++)
				if (no(x[k][i], y[k][i], x[m][j], y[m][j], len)) {
					int I = i * 2 + k, J = j * 2 + m;
					g[I ^ 1][J] = g[J ^ 1][I] = 1;
				}
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					g[i][j] |= g[i][k] & g[k][j];
		for (int i = 0; i < N; i++)
			if (g[i][i ^ 1] & g[i ^ 1][i])
				return false;
		return true;
	}
	int getMaximum(vector<int> xa, vector<int> ya, vector<int> xb, vector<int> yb){
		x[0] = xa; x[1] = xb; y[0] = ya; y[1] = yb;
		n = (int)xa.size(); N = n * 2;
		int l = 0, r = 1000000000, m;
		while (l <= r) {
			m = (l + r) / 2;
			if (go(m))
				l = m + 1;
			else r = m - 1;
		}
		l--;
		if (l < 1)return 0;
		return l;
	}
};


