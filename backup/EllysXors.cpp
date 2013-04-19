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

long long get(long long N) {
	if (N == -1)return 0;
	return N & ((N % 2) ? 0LL : ~0LL) | ( ((N & 2LL)>>1) ^ (N & 1LL) );
}

class EllysXors {
	public:
	long long getXor(long long L, long long R) {
		return get(R)^get(L-1);
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
		cout << "Testing EllysXors (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1337443820;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysXors _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long L = 3LL;
				long long R = 10LL;
				_expected = 8LL;
				_received = _obj.getXor(L, R); break;
			}
			case 1:
			{
				long long L = 5LL;
				long long R = 5LL;
				_expected = 5LL;
				_received = _obj.getXor(L, R); break;
			}
			case 2:
			{
				long long L = 13LL;
				long long R = 42LL;
				_expected = 39LL;
				_received = _obj.getXor(L, R); break;
			}
			case 3:
			{
				long long L = 666LL;
				long long R = 1337LL;
				_expected = 0LL;
				_received = _obj.getXor(L, R); break;
			}
			case 4:
			{
				long long L = 1234567LL;
				long long R = 89101112LL;
				_expected = 89998783LL;
				_received = _obj.getXor(L, R); break;
			}
			case 5:
			{
				long long L = 0LL;
				long long R = 6LL;
				_expected = 7LL;
				_received = _obj.getXor(L, R); break;
			}
			case 6:
			{
				 
				long long L = 1234567891011LL;
				long long R = 1234567891111LL;
				_expected = 1234567891011LL;
				_received = _obj.getXor(L, R); break;
			}
			case 7:
			{
				long long L = 999999999999ll, R=  1000000000024ll;
				_expected = 8167LL;
				_received = _obj.getXor(L, R); break;
			}
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
