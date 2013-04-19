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

const long long MAXVAL = 1000000000LL * 100000000LL;
struct Matrix {
	static const int N = 12;
	long long a[N][N];
	long long &at(int i, int j) { return a[i][j]; }
	long long mult(long long a, long long b) {
		if (a <= 100000000LL && b <= 100000000LL)
			return a*b;
		double logs = log10(a)+log10(b);
		if (logs > 17.)
			return MAXVAL;
		return min(MAXVAL, a*b);
	}
	void operator *= (Matrix b) {
		long long c[N][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				c[i][j] = 0;
				for (int k = 0; k < N; k++)
					c[i][j] = min(MAXVAL, c[i][j] + mult(a[i][k], b.at(k,j)));
			}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a[i][j] = c[i][j];
	}
	Matrix() {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				a[i][j] = (i==j);
	}
};

int n;
Matrix linearOperator;

class Flags {
	public:
	
	long long countUp(long long upTo) {
		Matrix a = linearOperator, res;
		while (upTo) {
			if (upTo&1)
				res *= a;
			a *= a;
			upTo >>= 1;
		}

		long long result = 0;
		for (int i = 0; i < n; i++)
			result = min(result+res.at(i,n),(long long)1e17);
		return result;
	}
	
	long long numStripes(string numFlags, vector <string> forbidden) {
		long long need, L, R, M;
		
		// init
		sscanf(numFlags.c_str(), "%lld", &need);
		
		// linear operator matrix init
		n = (int)forbidden.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				linearOperator.at(i,j) = 1;
			linearOperator.at(i,n) = 1;
		}

		for (int i = 0, x; i < n; i++) {
			stringstream strm;
			strm << forbidden[i];
			while (strm >> x)
				linearOperator.at(i,x) = 0;
		}

		L = 1; R = (long long)1e17;		// binsearch bounds

		// binsearch
		while (L <= R) {
			M = (L+R)/2;
			if (countUp(M) >= need)
				R = M-1;
			else
				L = M+1;
		}

		return R+1;
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
		cout << "Testing Flags (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1339575022;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Flags _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string numFlags = "10";
				string forbidden[] = {"0","1 2","1 2"};
				_expected = 3LL;
				_received = _obj.numStripes(numFlags, vector <string>(forbidden, forbidden+sizeof(forbidden)/sizeof(string))); break;
			}
			case 1:
			{
				string numFlags = "100";
				string forbidden[] = {"0","1","2"};
				_expected = 6LL;
				_received = _obj.numStripes(numFlags, vector <string>(forbidden, forbidden+sizeof(forbidden)/sizeof(string))); break;
			}
			case 2:
			{
				string numFlags = "100000000000000000";
				string forbidden[] = {"0","1"};
				_expected = 50000000000000000LL;
				_received = _obj.numStripes(numFlags, vector <string>(forbidden, forbidden+sizeof(forbidden)/sizeof(string))); break;
			}
			case 3:
			{
				string numFlags = "10000000000000000";
				string forbidden[] = {"0 1", "0 1", "2 3 4", "2 3 4", "2 3 4"};
				_expected = 40LL;
				_received = _obj.numStripes(numFlags, vector <string>(forbidden, forbidden+sizeof(forbidden)/sizeof(string))); break;
			}
			case 4:
			{
				string numFlags = "10000000000000000";
				string forbidden[] = {"0 1 2 3 4 5 6 7 8 9", "0 1 3 4 5 6 7 8 9", "0 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", 
				                     "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", 
				                     "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9"};
				_expected = 4999999999999996LL;
				_received = _obj.numStripes(numFlags, vector <string>(forbidden, forbidden+sizeof(forbidden)/sizeof(string))); break;
			}
			case 5:
			{
				string numFlags = "5";
				string forbidden[] = {"0","1","2","3","4","5"};
				_expected = 1LL;
				_received = _obj.numStripes(numFlags, vector <string>(forbidden, forbidden+sizeof(forbidden)/sizeof(string))); break;
			}
			/*case 6:
			{
				string numFlags = ;
				string forbidden[] = ;
				_expected = LL;
				_received = _obj.numStripes(numFlags, vector <string>(forbidden, forbidden+sizeof(forbidden)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string numFlags = ;
				string forbidden[] = ;
				_expected = LL;
				_received = _obj.numStripes(numFlags, vector <string>(forbidden, forbidden+sizeof(forbidden)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string numFlags = ;
				string forbidden[] = ;
				_expected = LL;
				_received = _obj.numStripes(numFlags, vector <string>(forbidden, forbidden+sizeof(forbidden)/sizeof(string))); break;
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
