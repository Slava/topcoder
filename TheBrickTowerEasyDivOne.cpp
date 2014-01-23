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

class TheBrickTowerEasyDivOne {
	public:
	int find(int redCount, int redHeight, int blueCount, int blueHeight) {
		if (redHeight == blueHeight) {
			int num = min(redCount,blueCount)*2;
			if (num/2+1 <= redCount || num/2+1 <= blueCount)
				num++;
			return num;
		}
		int num = min(redCount,blueCount), res = 0;
		res += num*2;
		if (num+1 <= blueCount)
			res++;
		if (num+1 <= redCount)
			num++;
		res += num;
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
		cout << "Testing TheBrickTowerEasyDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1346515826;
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
		TheBrickTowerEasyDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int redCount = 1;
				int redHeight = 2;
				int blueCount = 3;
				int blueHeight = 4;
				_expected = 4;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 1:
			{
				int redCount = 4;
				int redHeight = 4;
				int blueCount = 4;
				int blueHeight = 7;
				_expected = 12;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 2:
			{
				int redCount = 7;
				int redHeight = 7;
				int blueCount = 4;
				int blueHeight = 4;
				_expected = 13;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 3:
			{
				int redCount = 47;
				int redHeight = 47;
				int blueCount = 47;
				int blueHeight = 47;
				_expected = 94;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 4:
			{
				int redCount = 1;
				int redHeight = 5;
				int blueCount = 2;
				int blueHeight = 5;
				_expected = 3;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 5:
			{
				int redCount = 4;
				int redHeight = 4;
				int blueCount = 7;
				int blueHeight = 7;
				_expected = 13;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 6:
			{
				int redCount = 4;
				int redHeight = 7;
				int blueCount = 4;
				int blueHeight = 4;
				_expected = 12;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 7:
			{
				int redCount = 0;
				int redHeight = 7;
				int blueCount = 4;
				int blueHeight = 4;
				_expected = 1;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 8:
			{
				int redCount = 4;
				int redHeight = 7;
				int blueCount = 0;
				int blueHeight = 4;
				_expected = 1;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 9:
			{
				int redCount = 4;
				int redHeight = 4;
				int blueCount = 0;
				int blueHeight = 4;
				_expected = 1;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
			}
			case 10:
			{
				int redCount = 4;
				int redHeight = 4;
				int blueCount = 4;
				int blueHeight = 4;
				_expected = 8;
				_received = _obj.find(redCount, redHeight, blueCount, blueHeight); break;
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
