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

long long a[3], b[2];

class FoxPaintingBalls {
	public:
	long long theMax(long long R, long long G, long long B, int N) {
		if (N == 1)
			return (R+G+B);
		long long K = N / 3, X;
		X = (3*K*(long long)K+K)/2;
		if (N % 3 >= 1)
			X += K;
		if (N % 3 == 2)
			X += K+1;
		if (N % 3 == 0 || N % 3 == 2)
			return min(min(R,G),B)/X;
		long long l = 0, r = R+G+B, m, res=0;
		while (l <= r) {
			m = (l+r)/2;
			if (min(min(R,G),B)/X >= m && R+G+B-m*X*3 >= m)
				res=m,l = m+1;
			else
				r = m-1;
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
		cout << "Testing FoxPaintingBalls (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1345165803;
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
		FoxPaintingBalls _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long R = 2LL;
				long long G = 2LL;
				long long B = 2LL;
				int N = 3;
				_expected = 1LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 1:
			{
				long long R = 1LL;
				long long G = 2LL;
				long long B = 3LL;
				int N = 3;
				_expected = 0LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 2:
			{
				long long R = 8LL;
				long long G = 6LL;
				long long B = 6LL;
				int N = 4;
				_expected = 2LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 3:
			{
				long long R = 7LL;
				long long G = 6LL;
				long long B = 7LL;
				int N = 4;
				_expected = 2LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 4:
			{
				long long R = 100LL;
				long long G = 100LL;
				long long B = 100LL;
				int N = 4;
				_expected = 30LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 5:
			{
				long long R = 19330428391852493LL;
				long long G = 48815737582834113LL;
				long long B = 11451481019198930LL;
				int N = 3456;
				_expected = 5750952686LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 6:
			{
				long long R = 1LL;
				long long G = 1LL;
				long long B = 1LL;
				int N = 1;
				_expected = 3LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 7:
			{
				long long R = 9LL;
				long long G = 10LL;
				long long B = 11LL;
				int N = 4;
				_expected = 3LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 8:
			{
				long long R = 20LL;
				long long G = 15LL;
				long long B = 15LL;
				int N = 4;
				_expected = 5LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 9:
			{
				long long R = 21LL;
				long long G = 23LL;
				long long B = 26LL;
				int N = 4;
				_expected = 7LL;
				_received = _obj.theMax(R, G, B, N); break;
			}
			case 10:
			{
				long long R = 434532807763425372LL, G = 912245252707409536LL, B = 721365743254593093LL;
				int N = 31414801;
				_expected = 2641LL;
				_received = _obj.theMax(R, G, B, N); break;
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
