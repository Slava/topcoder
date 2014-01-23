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

double dp[52][100010], C[100010];
int n, m, walk;
vector<int>w, s;



double ternary(int k, int pos, int &l, int &r) {
	double res = 1e100;
	int ll, rr;
	while (r-l > 3) {
		ll = l + (r-l) / 3;
		rr = r - (r-l) / 3;

		double L = C[pos-ll] + dp[k][ll],
			   R = C[pos-rr] + dp[k][rr];
		if (L > R)
			l = ll;
		else
			r = rr;
	}
	for (int i = l; i <= r; i++) {
		double L = C[pos-i] + dp[k][i];
		if (res > L)
			res = L;
	}

	return res;
}

inline void remin(double &a, double b) {
	if (a > b)
		a = b;
}

class EllysRivers {
	public:
	double getMin(int length, int walk, vector <int> width, vector <int> speed) {
		n = length+1;
		m = (int)width.size()+1;
		w = width;
		s = speed;
		::walk = walk;
		int l = 0, r = 0;
		for (int i = 0; i < n; i++)
			dp[0][i] = i / (double)walk;
		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++)
				C[i] = sqrt(w[j-1]*1.0*w[j-1]+i*1.0*i)/s[j-1];
			for (int i = 0; i < n; i++) {
				dp[j][i] = 1e100;
				if (i) remin(dp[j][i], dp[j][i-1] + 1./walk);
				remin(dp[j][i], ternary(j-1, i, l = 0, r = i));
			}
		}
		return dp[m-1][n-1];
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
		cout << "Testing EllysRivers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1337444362;
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
		EllysRivers _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 10;
				int walk = 3;
				int width[] = {5, 2, 3};
				int speed[] = {5, 2, 7};
				_expected = 3.231651964071508;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 1:
			{
				int length = 10000;
				int walk = 211;
				int width[] = {911};
				int speed[] = {207};
				_expected = 48.24623664712219;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 2:
			{
				int length = 1337;
				int walk = 2;
				int width[] = {100, 200, 300, 400};
				int speed[] = {11, 12, 13, 14};
				_expected = 128.57830549575695;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 3:
			{
				int length = 77;
				int walk = 119;
				int width[] = {11, 12, 13, 14};
				int speed[] = {100, 200, 300, 400};
				_expected = 0.3842077071089629;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 4:
			{
				int length = 7134;
				int walk = 1525;
				int width[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393};
				int speed[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057};
				_expected = 214.6509731258811;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 5:
			{
				int length = 21114;
				int walk = 913309;
				int width[] = {652943};
				int speed[] = {298158};
				_expected = 2.1910674507909613;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 6:
			{
				int length = 100000;
				int walk = 1;
				int width[] = {1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000, 1000000};
				int speed[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 5.000009999990004E7;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			/*case 7:
			{
				int length = ;
				int walk = ;
				int width[] = ;
				int speed[] = ;
				_expected = ;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
