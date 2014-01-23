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

bool u[100][1025];
int dp[100][1025];
vector<int> a;
int k, n;

int go(int pr, int K) {
	if (K > 1024)return 100000000;
	if (pr == n)return 0;
	int &res = dp[pr][K];
	if (u[pr][K])
		return res;
	u[pr][K] = 1;
	res = (int)1e9;

	int first = 0;
	for (int i = 0; i <= min(K, n-pr); i++) {
		if(i)first = max(first, a[pr+i-1]);
		int time = max(first, go(pr+i, (K-i)*2)?go(pr+i, (K-i)*2)+k:0);
		res = min(res, time);
	}

	return res;
}

class FoxAndDoraemon {
	public:
	int minTime(vector <int> workCost, int splitCost) {
		sort (workCost.begin(), workCost.end());
		reverse (workCost.begin(), workCost.end());
		a = workCost;
		k = splitCost;
		n = (int)a.size();

		return go(0,1);
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
		cout << "Testing FoxAndDoraemon (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1333815570;
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
		FoxAndDoraemon _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int workCost[] = {1,2};
				int splitCost = 1000;
				_expected = 1002;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 1:
			{
				int workCost[] = {3,6,9,12};
				int splitCost = 1000;
				_expected = 2012;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 2:
			{
				int workCost[] = {1000,100,10,1};
				int splitCost = 1;
				_expected = 1001;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 3:
			{
				int workCost[] = {1712,1911,1703,1610,1697,1612};
				int splitCost = 100;
				_expected = 2012;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 4:
			{
				int workCost[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
				int splitCost = 3000;
				_expected = 15000;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			case 5:
			{
				int workCost[] = {58};
				int splitCost = 3600;
				_expected = 58;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}
			/*case 6:
			{
				int workCost[] = ;
				int splitCost = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}*/
			/*case 7:
			{
				int workCost[] = ;
				int splitCost = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
			}*/
			/*case 8:
			{
				int workCost[] = ;
				int splitCost = ;
				_expected = ;
				_received = _obj.minTime(vector <int>(workCost, workCost+sizeof(workCost)/sizeof(int)), splitCost); break;
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
