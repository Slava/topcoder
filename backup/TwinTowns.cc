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
#define abs(x) (x<0?-(x):x)

pair<int,int> dp[1<<20];
bool g[10][10];
int w[10][10];

bool operator < (pair<int,int> a, pair<int,int> b) {
	return a.first > b.first || (a.first == b.first && a.second < b.second);
}

pair<int,int> min(pair<int,int> a, pair<int,int> b) {
	return a < b ? a : b;
}

int get(int m, int x) {
	return 3 & (m >> (x*2));
}

class TwinTowns{
	public:
		vector <int> optimalTwinTowns(vector <int> x, vector <int> y, int maxPartners, int minDistance){
			fill(dp,dp+(1<<20),pair<int,int>(0,0));
			int n = (int)x.size();
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					g[i][j] = g[j][i] = abs(x[i]-x[j])+abs(y[i]-y[j]) >= minDistance,
						w[i][j] = w[j][i] = abs(x[i]-x[j])+abs(y[i]-y[j]);

			pair<int,int> ans(0,0);
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					for (int m = (1<<(n*2)) - 1; m >= 0; m--)
						if (g[i][j] && get(m,i) < maxPartners && get(m,j) < maxPartners) {
							int to = m + (1 << (i*2)) + (1 << (j*2));
							dp[to] = min(dp[to], pair<int,int> (dp[m].first + 1, dp[m].second + w[i][j]));
						}

			for (int i = 0; i < (1 << (n*2)); i++)
				ans = min(ans, dp[i]);

			vector<int> res(2);
			res[0] = ans.first;
			res[1] = ans.second;
			return res;
		}
};


