#ifdef gosolve

class MagicalGirlLevelOneDivOne {
public:
	string isReachable(vector <int> jumpTypes, int x, int y) {
		if (abs(x%2) == abs(y%2))
			return "YES";
		for (int i = 0; i < (int)jumpTypes.size(); i++)
			if (jumpTypes[i] % 2 == 0)
				return "YES";
		return "NO";
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
		cout << "Testing MagicalGirlLevelOneDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361698004;
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
		MagicalGirlLevelOneDivOne _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int jumpTypes[] = {2};
				int x = 5;
				int y = 4;
				_expected = "YES";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			case 1:
			{
				int jumpTypes[] = {3};
				int x = 5;
				int y = 4;
				_expected = "NO";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			case 2:
			{
				int jumpTypes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				int x = 1000000000;
				int y = -999999999;
				_expected = "YES";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			case 3:
			{
				int jumpTypes[] = {999999999};
				int x = 999999999;
				int y = 0;
				_expected = "NO";
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}
			/*case 4:
			{
				int jumpTypes[] = ;
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}*/
			/*case 5:
			{
				int jumpTypes[] = ;
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
			}*/
			/*case 6:
			{
				int jumpTypes[] = ;
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.isReachable(vector <int>(jumpTypes, jumpTypes+sizeof(jumpTypes)/sizeof(int)), x, y); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE

#endif
// imslavko
