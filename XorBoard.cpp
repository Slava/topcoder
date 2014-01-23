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

long long MD = 555555555LL;
long long Mod(long long res) {
	return ((res%MD)+MD)%MD;
}

int n, m, r, c, s;
long long C[2400][2400];

bool solve(int r, int c) {
	long long res = r * m;
	res += c * n;
	res -= r * c * 2;
	return res == s;
}


class XorBoard {
	public:
	int count(int H, int W, int Rcount, int Ccount, int S) {
		for (int i = 0; i < 2400; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j++)
				C[i][j] = (C[i-1][j] + C[i-1][j-1])%MD;
		}
		n = H; m = W; r = Rcount; c = Ccount; s = S;

		long long res = 0;
		for (int i = (r&1); i <= min(r,n); i += 2)
			for (int j = (c&1); j <= min(c,m); j += 2) {
				if (!solve(i,j))continue;
				int I = (r-i)/2, J = (c-j)/2;
				long long t = 
					Mod(Mod(C[n][i]*C[m][j])*Mod(C[n+I-1][n-1]*C[m+J-1][m-1]));
				res = (t+res)%MD;	
			}
		return (int)res;
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
		cout << "Testing XorBoard (555.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1347247963;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 555.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		XorBoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int H = 2;
				int W = 2;
				int Rcount = 2;
				int Ccount = 2;
				int S = 4;
				_expected = 4;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			case 1:
			{
				int H = 2;
				int W = 2;
				int Rcount = 0;
				int Ccount = 0;
				int S = 1;
				_expected = 0;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			case 2:
			{
				int H = 10;
				int W = 20;
				int Rcount = 50;
				int Ccount = 40;
				int S = 200;
				_expected = 333759825;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			case 3:
			{
				int H = 1200;
				int W = 1000;
				int Rcount = 800;
				int Ccount = 600;
				int S = 4000;
				_expected = 96859710;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			case 4:
			{
				int H = 555;
				int W = 555;
				int Rcount = 555;
				int Ccount = 555;
				int S = 5550;
				_expected = 549361755;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			case 5:
			{
				int H = 2;
				int W = 4;
				int Rcount = 10;
				int Ccount = 0;
				int S = 8;
				_expected = 5;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}
			/*case 6:
			{
				int H = ;
				int W = ;
				int Rcount = ;
				int Ccount = ;
				int S = ;
				_expected = ;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
			}*/
			/*case 7:
			{
				int H = ;
				int W = ;
				int Rcount = ;
				int Ccount = ;
				int S = ;
				_expected = ;
				_received = _obj.count(H, W, Rcount, Ccount, S); break;
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
