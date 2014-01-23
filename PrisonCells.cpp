#ifdef gosolve

int A[5][5];
int tryout(int mask, int m, int n) {
	int closest = 1<<30;
	memset(A, 0, sizeof A);
	for (int i = 0, k = 0; i < n; i++)
		for (int j = 0; j < m; j++, k++) {
			A[i][j] = (mask>>k)&1;
			if (!A[i][j])
				continue;

			for (int I = 0; I < n; I++)
				for (int J = 0; J < m; J++)
					if (A[I][J] && !(i == I && j == J))
						closest = min(closest, abs(i-I)+abs(j-J));
		}
//	cerr << mask << " " << closest << endl;
	return closest;
}

int res;
class PrisonCells {
public:
	int scatter(int m, int n, int nr) {
		int N = n * m, best = -1;
		res = -1;
		for (int i = 0; i < (1 << N); i++) {
			if (__builtin_popcount(i) != nr)
				continue;
			int cur = tryout(i, m, n);
			if (cur > best) {
				res = i;
				best = cur;
			}
		}
		return best;
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
#define abs(X) (X<0?-(X):X)

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
		cout << "Testing PrisonCells (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1359441532;
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
		PrisonCells _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 3;
				int n = 4;
				int nr = 2;
				_expected = 5;
				_received = _obj.scatter(m, n, nr); break;
			}
			case 1:
			{
				int m = 4;
				int n = 4;
				int nr = 3;
				_expected = 4;
				_received = _obj.scatter(m, n, nr); break;
			}
			case 2:
			{
				int m = 4;
				int n = 4;
				int nr = 4;
				_expected = 3;
				_received = _obj.scatter(m, n, nr); break;
			}
			case 3:
			{
				int m = 4;
				int n = 4;
				int nr = 16;
				_expected = 1;
				_received = _obj.scatter(m, n, nr); break;
			}
			case 4:
			{
				int m = 1;
				int n = 3;
				int nr = 2;
				_expected = 2;
				_received = _obj.scatter(m, n, nr); break;
			}
			/*case 5:
			{
				int m = ;
				int n = ;
				int nr = ;
				_expected = ;
				_received = _obj.scatter(m, n, nr); break;
			}*/
			/*case 6:
			{
				int m = ;
				int n = ;
				int nr = ;
				_expected = ;
				_received = _obj.scatter(m, n, nr); break;
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
