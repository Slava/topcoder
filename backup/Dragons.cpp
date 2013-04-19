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

#define int long long
vector<int> a, b, aa, bb;
bool ok[6][6] = {
{0,0,1,1,1,1},
{0,0,1,1,1,1},
{1,1,0,0,1,1},
{1,1,0,0,1,1},
{1,1,1,1,0,0},
{1,1,1,1,0,0},
};

void add(int &a, int &b, int aa, int bb) {
	bb *= 4;
//	printf("%lld/%lld += %lld/%lld = ", a, b, aa, bb);fflush(stdout);
	if (b != bb) {
		int lcm = b / __gcd(b,bb) * bb;
		a *= lcm / b;
		aa *= lcm / bb;
		b = lcm;
	}
	a += aa;
	int g = __gcd(a,b);
	a /= g;
	b /= g;
//	printf("%lld/%lld\n", a, b);fflush(stdout);
}

#undef int
class Dragons {
	public:
	string snaug(vector <int> initialFood, int rounds) {
		a.resize(6);
		for (int i = 0; i < 6; i++)
			a[i] = initialFood[i];
		b = vector<long long>(6, 1LL);
		while (rounds--) {
			aa = vector<long long>(6,0LL);
			bb = vector<long long>(6,1LL);
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
					if (ok[i][j])
						add(aa[i], bb[i], a[j], b[j]);
			a = aa;
			b = bb;
		}
		stringstream strm;
		if (b[2] != 1)
			strm << a[2] << "/" << b[2];
		else
			strm << a[2];
		return strm.str();
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
		cout << "Testing Dragons (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1339573657;
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
		Dragons _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int initialFood[] = {0, 0, 4, 0, 0, 0};
				int rounds = 2;
				_expected = "1";
				_received = _obj.snaug(vector <int>(initialFood, initialFood+sizeof(initialFood)/sizeof(int)), rounds); break;
			}
			case 1:
			{
				int initialFood[] = {0, 0, 4, 0, 0, 0};
				int rounds = 3;
				_expected = "1/2";
				_received = _obj.snaug(vector <int>(initialFood, initialFood+sizeof(initialFood)/sizeof(int)), rounds); break;
			}
			case 2:
			{
				int initialFood[] = {1000, 1000, 1000, 1000, 1000, 1000};
				int rounds = 45;
				_expected = "1000";
				_received = _obj.snaug(vector <int>(initialFood, initialFood+sizeof(initialFood)/sizeof(int)), rounds); break;
			}
			case 3:
			{
				int initialFood[] = {1, 2, 3, 4, 5, 6};
				int rounds = 45;
				_expected = "7/2";
				_received = _obj.snaug(vector <int>(initialFood, initialFood+sizeof(initialFood)/sizeof(int)), rounds); break;
			}
			/*case 4:
			{
				int initialFood[] = ;
				int rounds = ;
				_expected = ;
				_received = _obj.snaug(vector <int>(initialFood, initialFood+sizeof(initialFood)/sizeof(int)), rounds); break;
			}*/
			/*case 5:
			{
				int initialFood[] = ;
				int rounds = ;
				_expected = ;
				_received = _obj.snaug(vector <int>(initialFood, initialFood+sizeof(initialFood)/sizeof(int)), rounds); break;
			}*/
			/*case 6:
			{
				int initialFood[] = ;
				int rounds = ;
				_expected = ;
				_received = _obj.snaug(vector <int>(initialFood, initialFood+sizeof(initialFood)/sizeof(int)), rounds); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
