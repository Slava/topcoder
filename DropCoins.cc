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

#define ABS(x) (x<0?-(x):(x))

int n, m;
int a[100][100];

class DropCoins{
public:
	int getMinimum(vector<string> board, int K){
		n = board.size();
		m = board[0].size();
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (board[i - 1][j - 1] == 'o')
					a[i][j] = 1;
				else a[i][j] = 0;
		int res = 100000;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		
		for (int l = 1; l <= n; l++)
			for (int r = l; r <= n; r++)
				for (int u = 1; u <= m; u++)
					for (int d = u; d <= m; d++)
						if (a[r][d] - a[l - 1][d] - a[r][u - 1] + a[l - 1][u - 1] == K)
							res = min(res, min(l+l-2+n-r,n+n-r-r+l-1) + min(
										u+u-2+m-d,m+m-d-d+u-1));


		if (res == 100000)
			res = -1;

		return res;
	}
};


