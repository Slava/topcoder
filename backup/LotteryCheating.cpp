#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

int go(long long x, string b) {
	char s[20] = "";
	sprintf(s, "%0*lld", b.size(), x);
	string a = s;
	int cnt = 0;
	for (int i = 0; i < (int)b.size(); i++)
		if (a[i] != b[i])
			cnt++;
	return cnt;
}

class LotteryCheating {
public:
	int minimalChange(string ID) {
		int ans = 100;
		long long lim = 1;
		for (int i = 0; i < (int)ID.size(); i++)
			lim *= 10;
		for (long long i = 0; i * i < lim; i++)
			ans = min(ans, go(i*i, ID));
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
		cout << "Testing LotteryCheating (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1331017932;
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
		LotteryCheating _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string ID = "1";
				_expected = 0;
				_received = _obj.minimalChange(ID); break;
			}
			case 1:
			{
				string ID = "1234";
				_expected = 2;
				_received = _obj.minimalChange(ID); break;
			}
			case 2:
			{
				string ID = "9000000000";
				_expected = 1;
				_received = _obj.minimalChange(ID); break;
			}
			case 3:
			{
				string ID = "4294967296";
				_expected = 0;
				_received = _obj.minimalChange(ID); break;
			}
			case 4:
			{
				string ID = "7654321";
				_expected = 3;
				_received = _obj.minimalChange(ID); break;
			}
			/*case 5:
			{
				string ID = ;
				_expected = ;
				_received = _obj.minimalChange(ID); break;
			}*/
			/*case 6:
			{
				string ID = ;
				_expected = ;
				_received = _obj.minimalChange(ID); break;
			}*/
			/*case 7:
			{
				string ID = ;
				_expected = ;
				_received = _obj.minimalChange(ID); break;
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
