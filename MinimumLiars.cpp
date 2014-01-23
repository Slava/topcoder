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

using namespace std;

#define pb push_back
#define mp make_pair
#define foreach(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

class MinimumLiars {
	public:
	int getMinimum(vector <int> claim) {
		vector<int> c(201);
		int n = (int)claim.size();
		foreach(i,claim)
			c[*i]++;
		for (int i = 0; i < 200; i++) {
			if (n-c[i] == i)
				return i;
			c[i+1] += c[i];
		}
		return -1;
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
		cout << "Testing MinimumLiars (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1333813489;
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
		MinimumLiars _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int claim[] = {1,1,1,2};
				_expected = 1;
				_received = _obj.getMinimum(vector <int>(claim, claim+sizeof(claim)/sizeof(int))); break;
			}
			case 1:
			{
				int claim[] = {7,8,1};
				_expected = 2;
				_received = _obj.getMinimum(vector <int>(claim, claim+sizeof(claim)/sizeof(int))); break;
			}
			case 2:
			{
				int claim[] = {5,5,5,5,5};
				_expected = -1;
				_received = _obj.getMinimum(vector <int>(claim, claim+sizeof(claim)/sizeof(int))); break;
			}
			case 3:
			{
				int claim[] = {0,0,0,4,3,0};
				_expected = 2;
				_received = _obj.getMinimum(vector <int>(claim, claim+sizeof(claim)/sizeof(int))); break;
			}
			case 4:
			{
				int claim[] = {4,7,5};
				_expected = 3;
				_received = _obj.getMinimum(vector <int>(claim, claim+sizeof(claim)/sizeof(int))); break;
			}
			/*case 5:
			{
				int claim[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(claim, claim+sizeof(claim)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int claim[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(claim, claim+sizeof(claim)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int claim[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(claim, claim+sizeof(claim)/sizeof(int))); break;
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
