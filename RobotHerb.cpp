#ifdef gosolve

long long res;
class RobotHerb {
public:
	long long getdist(int T, vector <int> a) {
		vector<Int> r = get(T, a);
		return abs(r[0]) + abs(r[1]);
	}

	vector<Int> get(int T, vector<int> a) {
		vector<Int> res(2);
		if (!T)
			return res;
		if (T <= 4 || T % 4 != 0) {
			Int sum = 0;
			for (int i = 0; i < (int)a.size(); sum += a[i], i++)
				switch (sum%4) {
					case 0:
						res[0] += a[i];
						break;
					case 1:
						res[1] += a[i];
						break;
					case 2:
						res[0] -= a[i];
						break;
					case 3:
						res[1] -= a[i];
						break;
				}

			vector<Int> b = get(T-1, a);
			switch(sum%4) {
				case 0:
					res[0] += b[0];
					res[1] += b[1];
					break;
				case 1:
					res[1] += b[0];
					res[0] -= b[1];
					break;
				case 2:
					res[0] -= b[0];
					res[1] -= b[1];
					break;
				case 3:
					res[0] += b[1];
					res[1] -= b[0];
					break;
			}

			return res;
		}

		res = get(4, a);
		res[0] *= T/4;
		res[1] *= T/4;
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
		cout << "Testing RobotHerb (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361285941;
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
		RobotHerb _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int T = 1;
				int a[] = {1,2,3};
				_expected = 2LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int T = 100;
				int a[] = {1};
				_expected = 0LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int T = 5;
				int a[] = {1,1,2};
				_expected = 10LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int T = 1000000000;
				int a[] = {100};
				_expected = 100000000000LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int T = 570;
				int a[] = {2013,2,13,314,271,1414,1732};
				_expected = 4112LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 5:
			{
				int T = ;
				int a[] = ;
				_expected = LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int T = ;
				int a[] = ;
				_expected = LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int T = ;
				int a[] = ;
				_expected = LL;
				_received = _obj.getdist(T, vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
