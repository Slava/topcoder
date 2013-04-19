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
class FiveHundredEleven{
public:
	vector<vector<int> >dp;
	vector<int> a; int N;
	bool go(int m, int n) {
		if (dp[m][n] != -1)
			return dp[m][n];
		if (m == 511)
			return (dp[m][n] = 1);
		if (!n)
			return (dp[m][n] = 0);
		int insign = 0;
		for (int i = 0; i < N; i++)
			if ((m | a[i]) == m)
				insign++;
		insign -= N - n;
		if (insign && !go(m, n - 1))
			return (dp[m][n] = 1);
		for (int i = 0; i < N; i++)
			if ((a[i] | m) != m)
				if (!go(m | a[i], n - 1))
					return (dp[m][n] = 1);
		return (dp[m][n] = 0);
	}
	string theWinner(vector<int> b){
		a = b; N = a.size();
		dp.clear();
		dp.assign(512, vector<int>(51, -1));
		if (go(0, a.size()))
			return "Fox Ciel";
		return "Toastman";
	}
};


