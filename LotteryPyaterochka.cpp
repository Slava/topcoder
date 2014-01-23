#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

class LotteryPyaterochka {
public:
	double C(int n, int k) {
		if (n < k)return 0;
		double res = 1;
		for (int i = 1; i <= n; i++) {
			if (i <= n)
				res *= i;
			if (i <= k)
				res /= i;
			if (i <= n-k)
				res /= i;
		}
		return res;
	}

	double chanceToWin(int N) {
		double a = C(5,3) * C(N*5-5,2);
		double b = C(5,4) * C(N*5-5,1);
		double c = (a+b+1) / C(N*5,5);
		return c * N;
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
		cout << "Testing LotteryPyaterochka (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1331018701;
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
		LotteryPyaterochka _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				_expected = 1.0;
				_received = _obj.chanceToWin(N); break;
			}
			case 1:
			{
				int N = 2;
				_expected = 1.0;
				_received = _obj.chanceToWin(N); break;
			}
			case 2:
			{
				int N = 3;
				_expected = 0.5004995004995004;
				_received = _obj.chanceToWin(N); break;
			}
			case 3:
			{
				int N = 6;
				_expected = 0.13161551092585574;
				_received = _obj.chanceToWin(N); break;
			}
			/*case 4:
			{
				int N = ;
				_expected = ;
				_received = _obj.chanceToWin(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.chanceToWin(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = ;
				_received = _obj.chanceToWin(N); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
