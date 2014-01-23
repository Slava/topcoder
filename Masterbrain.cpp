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

string analyze(string a, string b) {
	int black = 0, white = 0;
	int u[256] = {0};
	for (int i = 0; i < 4; i++)
		u[a[i]]++;
	for (int i = 0; i < 4; i++)
		if (a[i] == b[i]) {
			black++;
			u[b[i]]--;
		}
	for (int i = 0; i < 4; i++)
		if (a[i] != b[i])
			if (u[b[i]]) {
				u[b[i]]--;
				white++;
			}
	stringstream strm;
	strm << black << "b " << white << "w";
	return strm.str();
}

class Masterbrain {
	public:
	int possibleSecrets(vector <string> guesses, vector <string> results) {
		int res = 0;
		for (int i = 0; i < 10000; i++) {
			char s[5];
			bool bad = 0;
			sprintf(s, "%04d", i);
			for (int j = 0; j < 4; j++)
				if (s[j] < '1' || s[j] > '7')
					bad = 1;
			if (bad)continue;
			int count = 0;
			for (int j = 0; j < (int)guesses.size(); j++) {
				if (analyze(string(s,s+4), guesses[j]) == results[j])
					count++;
			}
			if (count+1 == (int)guesses.size())
				res++;
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
		cout << "Testing Masterbrain (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1339571472;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Masterbrain _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string guesses[] = {"1575"} ;
				string results[] = {"4b 0w"};
				_expected = 2400;
				_received = _obj.possibleSecrets(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			case 1:
			{
				string guesses[] = {"1234"};
				string results[] = {"0b 4w"};
				_expected = 2392;
				_received = _obj.possibleSecrets(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			case 2:
			{
				string guesses[] = {"6172","6162","3617"};
				string results[] = {"3b 0w","2b 1w","0b 3w"};
				_expected = 14;
				_received = _obj.possibleSecrets(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			case 3:
			{
				string guesses[] = {"1513","5654","4564","1377","1671","1342"};
				string results[] = {"1b 0w","0b 1w","1b 0w","1b 0w","0b 1w","0b 1w"};
				_expected = 6;
				_received = _obj.possibleSecrets(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			case 4:
			{
				string guesses[] = {"2611", "1371", "7417", "2647", "3735", "4272", "2442", "3443", "1252", "3353"};
				string results[] = {"0b 2w","0b 2w","0b 1w","0b 2w","1b 0w","1b 0w","1b 0w","0b 1w","1b 1w","0b 1w"};
				_expected = 1;
				_received = _obj.possibleSecrets(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}
			/*case 5:
			{
				string guesses[] = ;
				string results[] = ;
				_expected = ;
				_received = _obj.possibleSecrets(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string guesses[] = ;
				string results[] = ;
				_expected = ;
				_received = _obj.possibleSecrets(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <string>(results, results+sizeof(results)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string guesses[] = ;
				string results[] = ;
				_expected = ;
				_received = _obj.possibleSecrets(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <string>(results, results+sizeof(results)/sizeof(string))); break;
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
