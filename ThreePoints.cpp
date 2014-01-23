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

const int N = 310000;

struct Fenwick {
	long long a[N];
	Fenwick() { memset(a,0,sizeof a); }
	void clear() { memset(a,0,sizeof a); }
	void inc(int i, long long x=1) {
		for (; i < N; i |= i+1)
			a[i] += x;
	}
	long long sum(int i) {
		long long r = 0;
		for (; i >= 0; i &= i+1, i--)
			r += a[i];
		return r;
	}
	long long sum(int l, int r) {
		return sum (r) - sum (l-1);
	}
} trl, trr;


int x[N], y[N], n, c[N];
pair<int,int> arr[N];

int getY(int x) { return lower_bound(y,y+n,x)-y; }
class ThreePoints {
	public:
	long long countColoring(int nn, int xzero, int xmul, int xadd, int xmod, int yzero, int ymul, int yadd, int ymod) {
		n = nn;
		x[0] = xzero;
		y[0] = yzero;

		for (int i = 1; i < n; i++) {
			x[i] = ((x[i-1] * 1LL * xmul) % xmod + xadd) % xmod;
			y[i] = ((y[i-1] * 1LL * ymul) % ymod + yadd) % ymod;
		}
		for (int i = 0; i < n; i++) {
			arr[i] = mp(x[i], y[i]);
			trr.inc(i);
		}
		sort(arr,arr+n);
		sort(y,y+n);

		long long res = 0;
		for (int i = 0; i < n; i++) {
			int Y = getY(arr[i].second);
			trr.inc(Y, -1);
			long long c = trr.sum(Y, n);
			res += c * (c-1) / 2;
			res -= trl.sum(Y)*trr.sum(Y,n);
			trl.inc(Y);
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
	if (argc == 1) 
	{
		cout << "Testing ThreePoints (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1338656214;
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
		ThreePoints _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 9;
				int xzero = 3;
				int xmul = 8;
				int xadd = 6;
				int xmod = 11;
				int yzero = 5;
				int ymul = 7;
				int yadd = 8;
				int ymod = 11;
				_expected = 8LL;
				_received = _obj.countColoring(N, xzero, xmul, xadd, xmod, yzero, ymul, yadd, ymod); break;
			}
			case 1:
			{
				int N = 4;
				int xzero = 9;
				int xmul = 6;
				int xadd = 8;
				int xmod = 10;
				int yzero = 4;
				int ymul = 8;
				int yadd = 5;
				int ymod = 10;
				_expected = 2LL;
				_received = _obj.countColoring(N, xzero, xmul, xadd, xmod, yzero, ymul, yadd, ymod); break;
			}
			case 2:
			{
				int N = 20;
				int xzero = 30;
				int xmul = 3;
				int xadd = 71;
				int xmod = 100;
				int yzero = 78;
				int ymul = 12;
				int yadd = 50;
				int ymod = 100;
				_expected = 263LL;
				_received = _obj.countColoring(N, xzero, xmul, xadd, xmod, yzero, ymul, yadd, ymod); break;
			}
			case 3:
			{
				int N = 300000;
				int xzero = 99097861;
				int xmul = 102766912;
				int xadd = 95284952;
				int xmod = 123456789;
				int yzero = 443104491;
				int ymul = 971853214;
				int yadd = 569775557;
				int ymod = 987654321;
				_expected = 749410681185726LL;
				_received = _obj.countColoring(N, xzero, xmul, xadd, xmod, yzero, ymul, yadd, ymod); break;
			}
			/*case 4:
			{
				int N = ;
				int xzero = ;
				int xmul = ;
				int xadd = ;
				int xmod = ;
				int yzero = ;
				int ymul = ;
				int yadd = ;
				int ymod = ;
				_expected = LL;
				_received = _obj.countColoring(N, xzero, xmul, xadd, xmod, yzero, ymul, yadd, ymod); break;
			}*/
			/*case 5:
			{
				int N = ;
				int xzero = ;
				int xmul = ;
				int xadd = ;
				int xmod = ;
				int yzero = ;
				int ymul = ;
				int yadd = ;
				int ymod = ;
				_expected = LL;
				_received = _obj.countColoring(N, xzero, xmul, xadd, xmod, yzero, ymul, yadd, ymod); break;
			}*/
			/*case 6:
			{
				int N = ;
				int xzero = ;
				int xmul = ;
				int xadd = ;
				int xmod = ;
				int yzero = ;
				int ymul = ;
				int yadd = ;
				int ymod = ;
				_expected = LL;
				_received = _obj.countColoring(N, xzero, xmul, xadd, xmod, yzero, ymul, yadd, ymod); break;
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
