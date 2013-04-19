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

int dp[60], n;
vector<long long> five;
class CuttingBitString {
	public:
	int getmin(string S) {
		for (long long i = 1; i < (1LL<<52); i *= 5)
			five.pb(i);
		n = (int)S.size();
		fill(dp,dp+60,1<<29);
		dp[0] = 0;
		for (int i = 0; i < n; i++)
			if (S[i] != '0' && dp[i] != 1<<29) {
				long long sum = 0;
				for (int j = i; j < n; j++) {
					sum <<= 1;
					sum += S[j]!='0';
					if (binary_search(five.begin(), five.end(), sum))
						dp[j+1] = min(dp[j+1], dp[i]+1);
				}
			}
			
		if (dp[n] == 1<<29)
			return -1;
		return dp[n];
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
		cout << "Testing CuttingBitString (255.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1347247255;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 255.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CuttingBitString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "101101101";
				_expected = 3;
				_received = _obj.getmin(S); break;
			}
			case 1:
			{
				string S = "1111101";
				_expected = 1;
				_received = _obj.getmin(S); break;
			}
			case 2:
			{
				string S = "00000";
				_expected = -1;
				_received = _obj.getmin(S); break;
			}
			case 3:
			{
				string S = "110011011";
				_expected = 3;
				_received = _obj.getmin(S); break;
			}
			case 4:
			{
				string S = "1000101011";
				_expected = -1;
				_received = _obj.getmin(S); break;
			}
			case 5:
			{
				string S = "111011100110101100101110111";
				_expected = 5;
				_received = _obj.getmin(S); break;
			}
			/*case 6:
			{
				string S = ;
				_expected = ;
				_received = _obj.getmin(S); break;
			}*/
			/*case 7:
			{
				string S = ;
				_expected = ;
				_received = _obj.getmin(S); break;
			}*/
			/*case 8:
			{
				string S = ;
				_expected = ;
				_received = _obj.getmin(S); break;
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
