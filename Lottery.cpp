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

long long c[110][10], f[10];

class Lottery {
	public:
	pair<long long,string> get(string rule) {
		stringstream strm;
		strm << rule;
		string name;
		getline(strm, name, ':');
		int choices, blanks, sorted, unique;
		strm >> choices >> blanks;
		char flag;
		strm >> flag;
		sorted = flag == 'T';
		strm >> flag;
		unique = flag == 'T';

		long long res = 0;
		if (sorted && unique) {
			res = c[choices][blanks];
		} else if (!sorted && unique) {
			res = c[choices][blanks] * f[blanks];
		} else if (!sorted && !unique) {
			res = 1;
			for (int i = 0; i < blanks; i++)
				res *= choices;
		} else {
			res = c[blanks+choices-1][blanks];
		}

		return mp(res, name);
	}

	vector <string> sortByOdds(vector <string> rules) {
		for (int i = 0; i < 110; i++) {
			c[i][0] = 1;
			for (int j = 1; j < 10; j++)
				c[i][j] = c[i-1][j] + c[i-1][j-1];
			f[i] = i ? f[i-1]*i : 1;
		}

		vector<pair<long long, string> >r;
		for (int i = 0; i < (int)rules.size(); i++)
			r.pb(get(rules[i]));
		sort (r.begin(), r.end());
		vector<string> res;
		foreach(i,r) {
			res.pb(i->second);
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
		cout << "Testing Lottery (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1338193077;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Lottery _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string rules[] = {"PICK ANY TWO: 10 2 F F"
				                 ,"PICK TWO IN ORDER: 10 2 T F"
				                 ,"PICK TWO DIFFERENT: 10 2 F T"
				                 ,"PICK TWO LIMITED: 10 2 T T"};
				string __expected[] = { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortByOdds(vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}
			case 1:
			{
				string rules[] = {"INDIGO: 93 8 T F",
				                  "ORANGE: 29 8 F T",
				                  "VIOLET: 76 6 F F",
				                  "BLUE: 100 8 T T",
				                  "RED: 99 8 T T",
				                  "GREEN: 78 6 F T",
				                  "YELLOW: 75 6 F F"};
				string __expected[] = { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortByOdds(vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}
			case 2:
			{
				string rules[] = {};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortByOdds(vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}
			/*case 3:
			{
				string rules[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortByOdds(vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string rules[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortByOdds(vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string rules[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortByOdds(vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
