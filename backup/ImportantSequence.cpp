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
#define Int long long

vector<Int> a;
string op;
int n;
class ImportantSequence {
	public:
	
	bool go(Int x) {
		if (x < 1)
			return 0;
		for (int i = 0; i < n; i++) {
			if (op[i] == '+')
				x = a[i] - x;
			else
				x -= a[i];
			if (x < 1)
				return 0;
		}
		return 1;
	}

	int getCount(vector <int> B, string operators) {
		for (int i = 0; i < (int)B.size(); i++)
			a.push_back(B[i]);
		n = (int)a.size();
		op = operators;
		Int Max = 0, x = 1;
		for (int i = 0; i < n; i++) {
			if (op[i] == '+') {
				x = a[i] - x;
				Max = max(Max, 1-x);
			}
			else {
				x = x - a[i];
				Max = max(Max, 1-x);
			}
		}

		Int d = Max+1;


		Int l = 0, r = 1LL<<62, m;

		while (l <= r) {
			m = (l+r) / 2;
			if (go(d+m)) {
				l = m+1;
			}
			else r = m-1;
		}

		cout << d << " " << l << endl;
		if (l >= 1LL<<32)
			return -1;
		return l;
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
		cout << "Testing ImportantSequence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1334142620;
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
		ImportantSequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int B[] = {3, -1, 7};
				string operators = "+-+";
				_expected = 2;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 1:
			{
				int B[] = {1};
				string operators = "-";
				_expected = -1;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 2:
			{
				int B[] = {1};
				string operators = "+";
				_expected = 0;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 3:
			{
				int B[] = {10};
				string operators = "+";
				_expected = 9;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 4:
			{
				int B[] = {540, 2012, 540, 2012, 540, 2012, 540};
				string operators = "-+-+-+-";
				_expected = 1471;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 5:
			{
				int B[] = {7, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 999999999, 1234, 4311};
				string operators =  "-------+--";
				_expected = 999994453;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			/*case 6:
			{
				int B[] = ;
				string operators = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}*/
			/*case 7:
			{
				int B[] = ;
				string operators = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
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
