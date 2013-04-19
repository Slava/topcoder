#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include<iostream>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

class SquaresInsideLattice {
public:
	long long howMany(int width, int height) {
		long long res = 0;
		
		for (int i = 1; i <= min(width,height); i++) {
			res += (height-i+1)*1LL*(width-i+1)*i;
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
		cout << "Testing SquaresInsideLattice (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1328790377;
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
		SquaresInsideLattice _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 1;
				int height = 1;
				_expected = 1LL;
				_received = _obj.howMany(width, height); break;
			}
			case 1:
			{
				int width = 2;
				int height = 3;
				_expected = 10LL;
				_received = _obj.howMany(width, height); break;
			}
			case 2:
			{
				int width = 3;
				int height = 3;
				_expected = 20LL;
				_received = _obj.howMany(width, height); break;
			}
			case 3:
			{
				int width = 27;
				int height = 19;
				_expected = 23940LL;
				_received = _obj.howMany(width, height); break;
			}
			/*case 4:
			{
				int width = ;
				int height = ;
				_expected = LL;
				_received = _obj.howMany(width, height); break;
			}*/
			/*case 5:
			{
				int width = ;
				int height = ;
				_expected = LL;
				_received = _obj.howMany(width, height); break;
			}*/
			/*case 6:
			{
				int width = ;
				int height = ;
				_expected = LL;
				_received = _obj.howMany(width, height); break;
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
