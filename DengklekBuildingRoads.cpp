#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) (((x)>>(y))&1)
#define Mod 1000000007LL

string testcase;
int bits(int x) {
	int res = 0;
	while(x>0) {
		if (x&1)
			res++;
		x>>=1;
	}
	return res;
}

int mod(long long x) {
	if (x >= Mod)
		x %= Mod;
	return (int)x;
}

long long dp[31][31][1<<9];
long long c[300][300];
class DengklekBuildingRoads {
public:
	int numWays(int N, int M, int K) {
		dp[1][M][0] = 1;
		c[0][0] = 1;
		for (int i = 1; i < 300; i++)
			for (int j = 0; j <= i; j++) {
				if (!j)c[i][j] = 1;
				else c[i][j] = mod(c[i-1][j-1]+0LL+c[i-1][j]);
			}
		for (int i = 1; i < N; i++)
			for (int j = 0; j <= M; j++)
				for (int k = 0; k < (1<<K); k++) if (dp[i][j][k])
					for (int toP = 0; toP < (1<<min(K,i)); toP++) {
						int change = bits(toP^k);
						if (change > j)
							continue;
						int nmask = toP << 1;
						nmask += change&1;
						if (bit(nmask,K))
							continue;

						dp[i+1][j-change][nmask] += dp[i][j][k];
						dp[i+1][j-change][nmask] %= Mod;
					}
		long long res = 0, par = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < i; j++)
				if (i-j <= K)
					par++;
		for (int i = 0; i <= M; i += 2) {
			res += c[par+i/2-1][i/2] * dp[N][i][0];
			res %= Mod;
		}

		return res;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc>1)testcase = argv[1];
	if (argc == 1) 
	{
		cout << "Testing DengklekBuildingRoads (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1328804798;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DengklekBuildingRoads _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int M = 4;
				int K = 1;
				_expected = 3;
				_received = _obj.numWays(N, M, K); break;
			}
			case 1:
			{
				int N = 4;
				int M = 3;
				int K = 3;
				_expected = 4;
				_received = _obj.numWays(N, M, K); break;
			}
			case 2:
			{
				int N = 2;
				int M = 1;
				int K = 1;
				_expected = 0;
				_received = _obj.numWays(N, M, K); break;
			}
			case 3:
			{
				int N = 5;
				int M = 0;
				int K = 3;
				_expected = 1;
				_received = _obj.numWays(N, M, K); break;
			}
			case 4:
			{
				int N = 10;
				int M = 20;
				int K = 5;
				_expected = 26964424;
				_received = _obj.numWays(N, M, K); break;
			}
			case 5:
			{
				int N = 3;
				int M = 4;
				int K = 2;
				_expected = 6;
				_received = _obj.numWays(N, M, K); break;
			}
			case 6:
			{
				int N = 30;
				int M = 30;
				int K = 4;
				_expected = 457088350;
				_received = _obj.numWays(N, M, K); break;
			}
			/*case 7:
			{
				int N = ;
				int M = ;
				int K = ;
				_expected = ;
				_received = _obj.numWays(N, M, K); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
