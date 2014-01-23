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

long long mod = 1000000007,
	 dp[230][200];

class NoRepeatPlaylist{
public:
	int numPlaylists(int N, int M, int P){
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 1; i <= P; i++)
			for (int j = 1; j <= N; j++) {
				dp[i][j] += dp[i-1][j-1]*(N-j+1) + dp[i-1][j]*max(j-M,0);
				dp[i][j] %= mod;
			}

		int res = dp[P][N]%mod;
		return res;
	}
};


