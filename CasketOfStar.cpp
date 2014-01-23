#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

const int N = 50;
int dp[N][N][N][N], a[N];
bool was[N][N][N][N];

int go(int l, int r, int ll, int rr) {
	int &res = dp[l][r][ll][rr];
	if (was[l][r][ll][rr])
		return res;
	was[l][r][ll][rr] = 1;
	if (l > r)
		return 0;
	for (int i = l; i <= r; i++)
		res = max(res, go(l,i-1,ll,i)+go(i+1,r,i,rr)+a[ll]*a[rr]);
	return res;
}

class CasketOfStar {
public:
	int maxEnergy(vector <int> weight) {
		for (int i = 0; i < (int)weight.size(); i++)
			a[i] = weight[i];
		return go(1,(int)weight.size()-2, 0, (int)weight.size()-1);
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
		cout << "Testing CasketOfStar (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1329584861;
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
		CasketOfStar _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int weight[] = {1,2,3,4};
				_expected = 12;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 1:
			{
				int weight[] = {100,2,1,3,100};
				_expected = 10400;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 2:
			{
				int weight[] = {2,2,7,6,90,5,9};
				_expected = 1818;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 3:
			{
				int weight[] = {477,744,474,777,447,747,777,474};
				_expected = 2937051;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 4:
			{
				int weight[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = 13;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			case 5:
			{
				int weight[] = {2,3};
				_expected = 0;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}
			/*case 6:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int weight[] = ;
				_expected = ;
				_received = _obj.maxEnergy(vector <int>(weight, weight+sizeof(weight)/sizeof(int))); break;
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
