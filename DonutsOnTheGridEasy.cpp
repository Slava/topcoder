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

const int N = 52;
int dp[N][N][N][N];
vector<string> g;

int go(int x, int y, int n, int m) {
	int &res = dp[x][y][n][m];
	if (n < 1 || m < 1)return res = 0;
	if (~res)return res;
	res = 0;
	if (n > 2 && m > 2) {
		bool isDonut = true;
		for (int i = 0; i < n; i++)
			isDonut &= g[x+i][y] == '0' && g[x+i][y+m-1] == '0';
		for (int i = 0; i < m; i++)
			isDonut &= g[x][y+i] == '0' && g[x+n-1][y+i] == '0';
		res = max(res, go(x+1,y+1,n-2,m-2) + isDonut);
	}
	res = max(res, go(x+1,y,n-1,m));
	res = max(res, go(x,y+1,n,m-1));
	res = max(res, go(x,y,n-1,m));
	res = max(res, go(x,y,n,m-1));
	return res;
}

class DonutsOnTheGridEasy {
	public:
	int calc(vector <string> grid) {
		g = grid;
		memset(dp,-1,sizeof dp);
		return go(0,0,grid.size(),grid[0].size());
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
		cout << "Testing DonutsOnTheGridEasy (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1347579749;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DonutsOnTheGridEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {"0000000"
				                ,"0.....0"
				                ,"0.00000"
				                ,"0.0..00"
				                ,"0.00000"
				                ,"0.....0"
				                ,"0000000"};
				_expected = 2;
				_received = _obj.calc(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {"000"
				                ,"0.0"
				                ,"000"};
				_expected = 1;
				_received = _obj.calc(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"..."
				                ,"..."
				                ,"..."};
				_expected = 0;
				_received = _obj.calc(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {"00.000"
				                ,"00.000"
				                ,"0.00.0"
				                ,"000.00"};
				_expected = 0;
				_received = _obj.calc(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {"0000000....",
				                 "0000000....",
				                 "0000000.000",
				                 "0000000.0.0",
				                 "0000000.000",
				                 "0000000....",
				                 "0000000...."};
				_expected = 3;
				_received = _obj.calc(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 5:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.calc(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.calc(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.calc(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
