#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

class FoxAndGCDLCM {
public:
	long long get(long long G, long long L) {
		if (L % G != 0)
			return -1;
		long long A = L / G;
		long long ans = -1;
		for (long long i = 1; i * i <= A; i++)
			if (A % i == 0) {
				long long sum = G * (A/i + i);
				if (__gcd(A/i, i) != 1)
					continue;
				if (ans == -1 || sum < ans)
					ans = sum;
			}

		return ans;
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
		cout << "Testing FoxAndGCDLCM (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1330794370;
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
		FoxAndGCDLCM _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long G = 2LL;
				long long L = 20LL;
				_expected = 14LL;
				_received = _obj.get(G, L); break;
			}
			case 1:
			{
				long long G = 5LL;
				long long L = 8LL;
				_expected = -1LL;
				_received = _obj.get(G, L); break;
			}
			case 2:
			{
				long long G = 1000LL;
				long long L = 100LL;
				_expected = -1LL;
				_received = _obj.get(G, L); break;
			}
			case 3:
			{
				long long G = 100LL;
				long long L = 1000LL;
				_expected = 700LL;
				_received = _obj.get(G, L); break;
			}
			case 4:
			{
				long long G = 10LL;
				long long L = 950863963000LL;
				_expected = 6298430LL;
				_received = _obj.get(G, L); break;
			}
			case 5:
			{
				long long G = 1LL;
				long long L = 55LL;
				_expected = 16LL;
				_received = _obj.get(G, L); break;
			}
			/*case 6:
			{
				long long G = LL;
				long long L = LL;
				_expected = LL;
				_received = _obj.get(G, L); break;
			}*/
			/*case 7:
			{
				long long G = LL;
				long long L = LL;
				_expected = LL;
				_received = _obj.get(G, L); break;
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
