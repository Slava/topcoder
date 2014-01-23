#ifdef gosolve

long long res;

int stringDifferentChars(string &a, string &b) {
	int differentCount = 0;
	for (int i = 0; i < (int)a.size(); i++)
		differentCount += a[i] != b[i];
	return differentCount;
}

class PasswordXGuessing {
public:
	long long howMany(vector <string> guesses) {
		for (int i = 0; i < (int)guesses[0].size(); i++)
			for (int k = 0; k < 10; k++) {
				string cur = guesses[0];
				if (cur[i] == k + '0')
					continue;
				cur[i] = k + '0';
				int differ = 0;
				for (int j = 0; j < (int)guesses.size(); j++)
					differ += stringDifferentChars(guesses[j], cur) == 1;
				if (differ == (int)guesses.size())
					res++;
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
		cout << "Testing PasswordXGuessing (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361636241;
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
		PasswordXGuessing _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string guesses[] = {"58", "47"};
				_expected = 2LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 1:
			{
				string guesses[] = {"539", "540", "541"};
				_expected = 1LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 2:
			{
				string guesses[] = {"12", "34", "56", "78"};
				_expected = 0LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 3:
			{
				string guesses[] = {"2", "3", "5"};
				_expected = 7LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 4:
			{
				string guesses[] = {"4747", "4747", "4747", "4747"};
				_expected = 36LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			/*case 5:
			{
				string guesses[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string guesses[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string guesses[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
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

#endif
// imslavko
