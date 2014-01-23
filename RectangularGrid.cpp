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

class RectangularGrid {
	public:
	long long countRectangles(int width, int height) {
		long long res = 0;
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
				res += (width-i)*1LL*(height-j);
		for (int i = 1; i <= min(height,width); i++)
			res -= (height-i+1)*1LL*(width-i+1);
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
		cout << "Testing RectangularGrid (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1339571234;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RectangularGrid _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 3;
				int height = 3;
				_expected = 22LL;
				_received = _obj.countRectangles(width, height); break;
			}
			case 1:
			{
				int width = 5;
				int height = 2;
				_expected = 31LL;
				_received = _obj.countRectangles(width, height); break;
			}
			case 2:
			{
				int width = 10;
				int height = 10;
				_expected = 2640LL;
				_received = _obj.countRectangles(width, height); break;
			}
			case 3:
			{
				int width = 1;
				int height = 1;
				_expected = 0LL;
				_received = _obj.countRectangles(width, height); break;
			}
			case 4:
			{
				int width = 592;
				int height = 964;
				_expected = 81508708664LL;
				_received = _obj.countRectangles(width, height); break;
			}
			/*case 5:
			{
				int width = ;
				int height = ;
				_expected = LL;
				_received = _obj.countRectangles(width, height); break;
			}*/
			/*case 6:
			{
				int width = ;
				int height = ;
				_expected = LL;
				_received = _obj.countRectangles(width, height); break;
			}*/
			/*case 7:
			{
				int width = ;
				int height = ;
				_expected = LL;
				_received = _obj.countRectangles(width, height); break;
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
