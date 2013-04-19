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
const int N = 1000;
class AddElectricalWires{
public:
	int n, col, num[N];
	bool a[N][N], in[N];int u[N];
	void dfs(int v) {
		u[v] = col; num[col]++;
		for (int i = 0; i < n; i++)
			if (a[v][i] && !u[i])
				dfs(i);
	}
	int maxNewWires(vector<string> wires, vector<int> C){
		n = wires.size();
		int res = 0;
		col = 0;
		memset(a, 0, sizeof a);
		memset(u, 0, sizeof u);
		memset(in, 0, sizeof in);
		memset(num, 0, sizeof num);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if(a[i][j] = wires[i][j] == '1')
					res--;
		col = 0;
		res /= 2;
		int left = n;
		int mx = 0;
		for (int i = 0; i < C.size(); i++) {
			col++;
			dfs(C[i]);
			left -= num[col];
			res += (num[col] - 1) * num[col] / 2;
			mx = max(mx, num[col]);
		}
		res += left * (left - 1) / 2 + left * mx;
		return res;
	}
};


