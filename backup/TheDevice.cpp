#ifdef gosolve

int count(string s, char x) {
	int res = 0;
	for (int i = 0; i < (int)s.size(); i++)
		res += x == s[i];
	return res;
}

int res;
class TheDevice {
public:
	int minimumAdditional(vector <string> plates) {
		int res = 0;
		for (int i = 0; i < (int)plates[0].size(); i++) {
			string s = "";
			for (int j = 0; j < (int)plates.size(); j++)
				s += plates[j][i];
			res = max(res, max(2-count(s,'1'),0)+max(1-count(s,'0'),0));
		}
		return res;
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
		cout << "Testing TheDevice (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1360203773;
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
		TheDevice _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string plates[] = {"010",
				                   "011",
				                   "101"};
				_expected = 1;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
			}
			case 1:
			{
				string plates[] = {"0",
				                   "1",
				                   "0",
				                   "1"};
				_expected = 0;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
			}
			case 2:
			{
				string plates[] = {"01010101",
				                   "10101010"};
				_expected = 1;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
			}
			case 3:
			{
				string plates[] = {"10010101011",
				                   "00010101001",
				                   "00100010111",
				                   "00101010101",
				                   "01010111101"};
				_expected = 1;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
			}
			case 4:
			{
				string plates[] = {"1101001011010",
				                   "0010000010101",
				                   "1010101011110",
				                   "1101010100111",
				                   "1011111110111"};
				_expected = 0;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
			}
			case 5:
			{
				string plates[] = {"0"};
				_expected = 2;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
			}
			case 6:
			{
				string plates[] = {"0", "1"
				};
				_expected = 1;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
			}
			case 7:
			{
				string plates[] = {"0", "0"};
				_expected = 2;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
			}
			case 8:
			{
				string plates[] = {"1", "1"};
				_expected = 1;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
			}
			case 9:

			{
				string plates[] = {"1"};
				_expected = 2;
				_received = _obj.minimumAdditional(vector <string>(plates, plates+sizeof(plates)/sizeof(string))); break;
				break;
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

#endif
// imslavko
