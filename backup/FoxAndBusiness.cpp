#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

int K, totalWork;
vector<int> a, p;

bool can(double A) {
	vector<double> v;
	for (int i = 0; i < (int)a.size(); i++)
		v.push_back(a[i] * 1. * (A - p[i]));
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	double sum = 0;
	for (int i = 0; i < K; i++)
		sum += v[i];
	return sum >= 3600 * K;
}

class FoxAndBusiness {
public:
	double minimumCost(int K, int totalWork, vector <int> a, vector <int> p) {
		::K = K; ::totalWork = totalWork; ::a = a; :: p = p;
		double l = 0, r = 1e30, m;
		for (int i = 0; i < 5000; i++) {
			m = (l + r) / 2.;
			if (can(m))
				r = m;
			else l = m;
		}
		return r * totalWork;
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
		cout << "Testing FoxAndBusiness (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1331014953;
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
		FoxAndBusiness _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 1;
				int totalWork = 10;
				int a[] = {10};
				int p[] = {20};
				_expected = 3800.0;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 1:
			{
				int K = 1;
				int totalWork = 100;
				int a[] = {50, 60};
				int p[] = {1000, 2000};
				_expected = 107200.0;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 2:
			{
				int K = 2;
				int totalWork = 300;
				int a[] = {10, 20, 47};
				int p[] = {15, 20, 98765};
				_expected = 77500.0;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 3:
			{
				int K = 4;
				int totalWork = 1000;
				int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				int p[] = {20, 30, 40, 58, 60, 70, 80, 90, 100, 150};
				_expected = 531764.705882353;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			/*case 4:
			{
				int K = ;
				int totalWork = ;
				int a[] = ;
				int p[] = ;
				_expected = ;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int K = ;
				int totalWork = ;
				int a[] = ;
				int p[] = ;
				_expected = ;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int K = ;
				int totalWork = ;
				int a[] = ;
				int p[] = ;
				_expected = ;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
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
