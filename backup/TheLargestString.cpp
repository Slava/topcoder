#ifdef gosolve

pair<string, string> dp[100][100];
string res;

class TheLargestString {
public:
	string find(string s, string t) {
		int n = s.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++) {
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				dp[i+1][j+1] = max(dp[i+1][j+1], mp(
					dp[i][j].first+s[i], dp[i][j].second+t[i]));
			}

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++) {
				res = max(res, dp[i][j].first + dp[i][j].second);
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

string randString(int sz) {
	string s(sz, 'a');
	for (int i = 0; i < sz; i++)
		s[i] = rand() % 26 + 'a';
	return s;
}

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		srand(time(0));
		cout << "Testing TheLargestString (300.0 points)" << endl << endl;
		for (int i = 0; i < 200; i++)
		{
			ostringstream s; s << argv[0] << " " << i << " " << rand();
			int exitCode = system(s.str().c_str());
			if (exitCode) {
				cout << "#" << i << ": Runtime Error" << endl;
				return 0;
			}
		}
		int T = time(NULL)-1364746213;
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
		int seed; istringstream(argv[2]) >> seed;
		srand(seed);
		TheLargestString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "ab";
				string t = "zy";
				_expected = "by";
				_received = _obj.find(s, t); break;
			}
			case 1:
			{
				string s = "abacaba";
				string t = "zzzaaaa";
				_expected = "cbaaaa";
				_received = _obj.find(s, t); break;
			}
			case 2:
			{
				string s = "x";
				string t = "x";
				_expected = "xx";
				_received = _obj.find(s, t); break;
			}
			case 3:
			{
				string s = "abbabbabbababaaaabbababab";
				string t = "bababbaabbbababbbbababaab";
				_expected = "bbbbbbbbbbbbbbbbbbaaab";
				_received = _obj.find(s, t); break;
			}
			case 4:
			{
				string s = "aaa";
				string t = "aba";
				_expected = "ab";
				_received = _obj.find(s, t); break;
			}
			case 5:
			{
				string s = "aaa";
				string t = "aab";
				_expected = "ab";
				_received = _obj.find(s, t); break;
			}
			case 6:
			{
				string s = "az";
				string t = "za";
				_expected = "za";
				_received = _obj.find(s, t); break;
			}
			default:exit(0);
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
			cout << "FAAAIIIL" << endl;
			return -1;
		}
	}
}

// END CUT HERE

#endif
// imslavko
