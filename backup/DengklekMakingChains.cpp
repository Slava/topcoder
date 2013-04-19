#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)
#define mp make_pair
#define pb push_back
vector<pair<int,int> > prefix, suffix; int full;

class DengklekMakingChains {
public:
	int maxBeauty(vector <string> chains) {
		int res = 0;
		for (int i = 0; i < (int)chains.size(); i++) {
			string s = chains[i];
			int a = s[0]=='.'?-1:s[0]-'0', b = s[1]=='.'?-1:s[1]-'0', c = s[2]=='.'?-1:s[2]-'0';
			if (a == -1 && c == -1 && b != -1) {
				res = max(res, b);
			}
			if (a != -1 && b != -1 && c != -1)
				full+=a+b+c;
			if (a != -1 && b == -1)
				prefix.pb(mp(a,i));
			if (a != -1 && b != -1 && c == -1)
				prefix.pb(mp(a+b,i));
			if (c != -1 && b == -1)
				suffix.pb(mp(c,i));
			if (c != -1 && b != -1 && a == -1)
				suffix.pb(mp(c+b,i));
		}

		prefix.pb(mp(0,-1));
		suffix.pb(mp(0,-2));
		sort (prefix.begin(), prefix.end()); reverse (prefix.begin(), prefix.end());
		sort (suffix.begin(), suffix.end()); reverse (suffix.begin(), suffix.end());
		for (int i = 0; i < (int)prefix.size(); i++)
			for (int j = 0; j < (int)suffix.size(); j++)
				if (prefix[i].second != suffix[j].second)
					res = max(res, prefix[i].first+suffix[j].first+full);

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
		cout << "Testing DengklekMakingChains (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1328803505;
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
		DengklekMakingChains _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chains[] = {".15", "7..", "402", "..3"};
				_expected = 19;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 1:
			{
				string chains[] = {"..1", "7..", "567", "24.", "8..", "234"};
				_expected = 36;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 2:
			{
				string chains[] = {"...", "..."};
				_expected = 0;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 3:
			{
				string chains[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
				_expected = 28;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 4:
			{
				string chains[] = {"..1", "3..", "2..", ".7."};
				_expected = 7;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 5:
			{
				string chains[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
				_expected = 58;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 6:
			{
				string chains[] = {".6.", "9.7"};
				_expected = 9;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 7:
			{
				string chains[] = {"4.5","5.4", ".9."};
				_expected = 10;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
			}
			case 8:
			{
				string chains[] = {".9."};
				_expected = 9;
				_received = _obj.maxBeauty(vector <string>(chains, chains+sizeof(chains)/sizeof(string))); break;
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
