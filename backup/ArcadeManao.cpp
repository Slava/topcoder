#ifdef gosolve

int res, fx, fy;
vector<string> a;
bool u[100][100];

#define f first
#define s second

class ArcadeManao {
public:

	bool can(int l) {
		memset(u, 0, sizeof u);
		vector<pair<int,int> > q;
		q.push_back(mp(a.size()-1,0));
		u[a.size()-1][0] = 1;
		for (int i = 0; i < q.size(); i++) {
			pair<int,int> cur = q[i];
			u[cur.f][cur.s] = 1;

			if (cur.s > 0 && a[cur.f][cur.s-1] == 'X' && !u[cur.f][cur.s-1]) {
				pair<int,int> to = mp(cur.f, cur.s-1);
				u[to.f][to.s] = 1;
				q.pb(to);
			}

			if (cur.s + 1 < a[0].size() && a[cur.f][cur.s+1] == 'X' && !u[cur.f][cur.s+1]) {
				pair<int,int> to = mp(cur.f, cur.s+1);
				u[to.f][to.s] = 1;
				q.pb(to);
			}

			for (int j = cur.f - l; j <= cur.f + l; j++) {
				pair<int,int> to = mp(j,cur.s);
				if (j < 0 || j >= a.size())
					continue;
				if (u[to.f][to.s] || a[to.f][to.s] != 'X')
					continue;
				u[to.f][to.s] = 1;
				q.pb(to);
			}

		}

		return u[fx][fy];
	}

	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		a = level;
		fx = coinRow - 1;
		fy = coinColumn - 1;

		for (int i = 0; i < 55; i++)
			if (can(i)) {
				return i;
			}
		return -1;
	}
};













#else
#define gosolve
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

#define mp make_pair
#define pb push_back

typedef long long Int;

#include __FILE__

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
		cout << "Testing ArcadeManao (256.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365729025;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 256.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ArcadeManao _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string level[] = {"XXXX....",
				                  "...X.XXX",
				                  "XXX..X..",
				                  "......X.",
				                  "XXXXXXXX"};
				int coinRow = 2;
				int coinColumn = 4;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 1:
			{
				string level[] = {"XXXX",
				                  "...X",
				                  "XXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 1;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 2:
			{
				string level[] = {"..X..",
				                  ".X.X.",
				                  "X...X",
				                  ".X.X.",
				                  "..X..",
				                  "XXXXX"};
				int coinRow = 1;
				int coinColumn = 3;
				_expected = 4;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 3:
			{
				string level[] = {"X"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 0;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 4:
			{
				string level[] = {"XXXXXXXXXX",
				                  "...X......",
				                  "XXX.......",
				                  "X.....XXXX",
				                  "..XXXXX..X",
				                  ".........X",
				                  ".........X",
				                  "XXXXXXXXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 5:
			{
				string level[] = {
					"...X..............................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"..................................................",
					"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
				};
				int coinRow = 1;
				int coinColumn = 4;
				_expected = 49;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			/*case 6:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}*/
			/*case 7:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
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

#endif
// imslavko
