// imslavko
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define foreach(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define all(c) c.begin(),c.end() 

int A[100][100], B[100][100];
long long dp[100][100];

long long MD = 1000000007LL;
long long MOD(long long x) {
	return (x % MD + MD ) % MD;
}

class TwoConvexShapes {
	public:
	vector<string> rotate(vector<string> b) {
		int n = (int)b.size(), m = (int)b[0].size();
		vector<string> a(m, string(n, '.'));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[j][i] = b[i][m-j-1];
		return a;
	}
	int countWays(vector <string> grid) {
		long long res = 0;
		for (int ik = 0; ik < 4; ik++) {
			int n = (int)grid.size(), m = (int)grid[0].size();

			res += go(grid,n,m);
			res = MOD(res);
			grid = rotate(grid);
		}
		int n = (int)grid.size(), m = (int)grid[0].size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				A[i][j] = grid[i][j] == 'W';
				B[i][j] = grid[i][j] == 'B';
				if (i && j) {
					A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
					B[i][j] += B[i-1][j] + B[i][j-1] - B[i-1][j-1];
				} else if (!i) {
					A[i][j] += A[i][j-1];
					B[i][j] += B[i][j-1];
				} else if (!j) {
					A[i][j] += A[i-1][j];
					B[i][j] += B[i-1][j];
				}
			}

		if (A[n-1][m-1] == 0)
			res -= 3;
		if (B[n-1][m-1] == 0)
			res -= 3;

		for (int i = 0; i < n-1; i++) {
			if (A[i][m-1] == 0 && B[n-1][m-1]-B[i][m-1] == 0)
				res--;
			if (B[i][m-1] == 0 && A[n-1][m-1]-A[i][m-1] == 0)
				res--;
		}

		for (int i = 0; i < m-1; i++) {
			if (A[n-1][i] == 0 && B[n-1][m-1]-B[n-1][i] == 0)
				res--;
			if (B[n-1][i] == 0 && A[n-1][m-1]-A[n-1][i] == 0)
				res--;
		}

		return (int)MOD(res);
	}
	int go(vector<string> a, int n, int m) {
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				A[i][j] = a[i][j] == 'W';
				if (j)
					A[i][j] += A[i][j-1];
			}
			for (int j = m-1; j >= 0; j--) {
				B[i][j] = a[i][j] == 'B';
				if (j!=m-1)
					B[i][j] += B[i][j+1];
			}
		}
		memset(dp, 0, sizeof dp);
		if (B[0][0] == 0)
			dp[0][0] = 1;
		for (int i = 1; i <= m; i++)
			if (A[0][i-1] == 0 && B[0][i] == 0)
				dp[0][i] = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= m; j++)
				if (dp[i][j])
					for (int k = j; k >= 0; k--)
						if ((!k || !A[i+1][k-1]) && B[i+1][k] == 0)
							dp[i+1][k] = MOD(dp[i+1][k] + dp[i][j]);
		return dp[n][0];
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
	if (argc == 1) 
	{
		cout << "Testing TwoConvexShapes (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1345685210;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TwoConvexShapes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"??",
				                 "??"};
				_expected = 14;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {"B?",
				                 "??"};
				_expected = 7;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"WWB",
				                 "WWW",
				                 "WWW",
				                 "WWW"};
				_expected = 1;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {"BBBBBB",
				                 "WWBBBB",
				                 "WBBBBB"};
				_expected = 0;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {"?BB?",
				                 "BBBB",
				                 "?BB?"};
				_expected = 5;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 5:
			{
				string grid[] = {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
				                 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"};
				_expected = 73741817;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 6:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.countWays(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
