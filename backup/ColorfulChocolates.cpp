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
#define abs(x) (x<0?-(x):x)

int ans = 1;
class ColorfulChocolates {
	public:
	int maximumSpread(string chocolates, int maxSwaps) {
		int n = (int)chocolates.size();
		for (int col = 'A'; col <= 'Z'; col++) {
			for (int l = 0; l < n; l++) 
				for (int s = 0; s < n; s++) {
				int score = 0, was = 0;
				for (int i = s; i < n; i++)
					if (chocolates[i] == col) {
						score += abs(l-i+was);
						was++;
						if (score <= maxSwaps && was+l <= n)
							ans = max(ans, was);
					}
			}
		}
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
		cout << "Testing ColorfulChocolates (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1345163567;
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
		ColorfulChocolates _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chocolates = "ABCDCBC";
				int maxSwaps = 1;
				_expected = 2;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 1:
			{
				string chocolates = "ABCDCBC";
				int maxSwaps = 2;
				_expected = 3;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 2:
			{
				string chocolates = "ABBABABBA";
				int maxSwaps = 3;
				_expected = 4;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 3:
			{
				string chocolates = "ABBABABBA";
				int maxSwaps = 4;
				_expected = 5;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 4:
			{
				string chocolates = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
				int maxSwaps = 77;
				_expected = 5;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 5:
			{
				string chocolates = "CBABBACBABABCCCCCAABBAACBBBBCBCAAA";
				int maxSwaps = 8;
				_expected = 7;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			/*case 6:
			{
				string chocolates = ;
				int maxSwaps = ;
				_expected = ;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}*/
			/*case 7:
			{
				string chocolates = ;
				int maxSwaps = ;
				_expected = ;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
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
