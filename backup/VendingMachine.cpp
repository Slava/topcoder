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
#include <cassert> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define foreach(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define all(c) c.begin(),c.end() 
#define abs(x) (x<0?-(x):x)

int N;
class VendingMachine {
	public:
	int getMax(vector<int> &c) {
		int m = 0;
		for (int i = 0; i < (int)c.size(); i++)
			m = max(m, c[i]);
		for (int i = 0; i < (int)c.size(); i++)
			if (m == c[i])
				return i;
		assert(0);
		return -1;
	}
	int getDist(int x, int y) {
		if (x > y) swap(x,y);
		return min(y-x, N-y+x);
	}
	int motorUse(vector <string> prices, vector <string> purchases) {
		int n = (int)prices.size();
		vector<vector<int> > pr(n, vector<int>());
		for (int i = 0; i < n; i++) {
			stringstream strm;
			strm << prices[i];
			int x;
			while (strm >> x)
				pr[i].pb(x);
		}
		int m = (int)pr[0].size();
		int k = (int)purchases.size();
		N = m;
		vector<int> purx(k), pury(k), purt(k);
		for (int i = 0; i < k; i++) {
			sscanf(purchases[i].c_str(), "%d,%d:%d", &purx[i], &pury[i], &purt[i]);
		}
		vector<int> cost(m);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cost[i] += pr[j][i];
		int res = 0, best, cur = 0;
		best = getMax(cost);
		res += getDist(cur, best);
		cur = best;

		for (int i = 0; i < k; i++) {
			int x = purx[i], y = pury[i], t = purt[i];
			if (pr[x][y] == 0)
				return -1;
			if (i && t-purt[i-1] >= 5) {
				best = getMax(cost);
				res += getDist(best, cur);
				cur = best;
			}

			res += getDist(cur, y);
			cur = y;

			cost[y] -= pr[x][y];
			pr[x][y] = 0;
		}

		best = getMax(cost);
		res += getDist(cur, best);
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
	if (argc == 1) 
	{
		cout << "Testing VendingMachine (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1338196633;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		VendingMachine _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string prices[] = {"100 100 100"};
				string purchases[] = {"0,0:0", "0,2:5", "0,1:10"};
				_expected = 4;
				_received = _obj.motorUse(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), vector <string>(purchases, purchases+sizeof(purchases)/sizeof(string))); break;
			}
			case 1:
			{
				string prices[] = {"100 200 300 400 500 600"};
				string purchases[] = {"0,2:0", "0,3:5", "0,1:10", "0,4:15"};
				_expected = 17;
				_received = _obj.motorUse(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), vector <string>(purchases, purchases+sizeof(purchases)/sizeof(string))); break;
			}
			case 2:
			{
				string prices[] = {"100 200 300 400 500 600"};
				string purchases[] = {"0,2:0", "0,3:4", "0,1:8", "0,4:12"};
				_expected = 11;
				_received = _obj.motorUse(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), vector <string>(purchases, purchases+sizeof(purchases)/sizeof(string))); break;
			}
			case 3:
			{
				string prices[] = {"100 100 100"};
				string purchases[] = {"0,0:10", "0,0:11"};
				_expected = -1;
				_received = _obj.motorUse(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), vector <string>(purchases, purchases+sizeof(purchases)/sizeof(string))); break;
			}
			case 4:
			{
				string prices[] = {"100 200 300",
				                   "600 500 400"};
				string purchases[] = {"0,0:0", "1,1:10", "1,2:20",
				                      "0,1:21", "1,0:22", "0,2:35"};
				_expected = 6;
				_received = _obj.motorUse(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), vector <string>(purchases, purchases+sizeof(purchases)/sizeof(string))); break;
			}
			/*case 5:
			{
				string prices[] = ;
				string purchases[] = ;
				_expected = ;
				_received = _obj.motorUse(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), vector <string>(purchases, purchases+sizeof(purchases)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string prices[] = ;
				string purchases[] = ;
				_expected = ;
				_received = _obj.motorUse(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), vector <string>(purchases, purchases+sizeof(purchases)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string prices[] = ;
				string purchases[] = ;
				_expected = ;
				_received = _obj.motorUse(vector <string>(prices, prices+sizeof(prices)/sizeof(string)), vector <string>(purchases, purchases+sizeof(purchases)/sizeof(string))); break;
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
