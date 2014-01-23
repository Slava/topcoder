#ifdef gosolve

int dp[50][50];
class PasswordXGrid {
public:
	int minSum(vector <string> horizontal, vector <string> vertical) {
		int N = (int)vertical.size(), M = (int)horizontal[0].size();
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= M; j++) {
				if (j != M)dp[i][j+1] = max(dp[i][j+1], dp[i][j] + horizontal[i][j]-'0');
				if (i != N)dp[i+1][j] = max(dp[i+1][j], dp[i][j] + vertical[i][j]-'0');
			}
		return dp[N][M];
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
		cout << "Testing PasswordXGrid (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361637177;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PasswordXGrid _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string horizontal[] = {"1","4"};
				string vertical[] = {"32"};
				_expected = 7;
				_received = _obj.minSum(vector <string>(horizontal, horizontal+sizeof(horizontal)/sizeof(string)), vector <string>(vertical, vertical+sizeof(vertical)/sizeof(string))); break;
			}
			case 1:
			{
				string horizontal[] = {"47", "59"};
				string vertical[] = {"361"};
				_expected = 19;
				_received = _obj.minSum(vector <string>(horizontal, horizontal+sizeof(horizontal)/sizeof(string)), vector <string>(vertical, vertical+sizeof(vertical)/sizeof(string))); break;
			}
			case 2:
			{
				string horizontal[] = {"36", "23", "49"};
				string vertical[] = {"890", "176"};
				_expected = 28;
				_received = _obj.minSum(vector <string>(horizontal, horizontal+sizeof(horizontal)/sizeof(string)), vector <string>(vertical, vertical+sizeof(vertical)/sizeof(string))); break;
			}
			case 3:
			{
				string horizontal[] = {"8888585","5888585"};
				string vertical[] = {"58585858"};
				_expected = 58;
				_received = _obj.minSum(vector <string>(horizontal, horizontal+sizeof(horizontal)/sizeof(string)), vector <string>(vertical, vertical+sizeof(vertical)/sizeof(string))); break;
			}
			case 4:
			{
				string horizontal[] = {"7777777","7777777","7777777","7777777"};
				string vertical[] = {"44444444","44444444","44444444"};
				_expected = 61;
				_received = _obj.minSum(vector <string>(horizontal, horizontal+sizeof(horizontal)/sizeof(string)), vector <string>(vertical, vertical+sizeof(vertical)/sizeof(string))); break;
			}
			/*case 5:
			{
				string horizontal[] = ;
				string vertical[] = ;
				_expected = ;
				_received = _obj.minSum(vector <string>(horizontal, horizontal+sizeof(horizontal)/sizeof(string)), vector <string>(vertical, vertical+sizeof(vertical)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string horizontal[] = ;
				string vertical[] = ;
				_expected = ;
				_received = _obj.minSum(vector <string>(horizontal, horizontal+sizeof(horizontal)/sizeof(string)), vector <string>(vertical, vertical+sizeof(vertical)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string horizontal[] = ;
				string vertical[] = ;
				_expected = ;
				_received = _obj.minSum(vector <string>(horizontal, horizontal+sizeof(horizontal)/sizeof(string)), vector <string>(vertical, vertical+sizeof(vertical)/sizeof(string))); break;
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
