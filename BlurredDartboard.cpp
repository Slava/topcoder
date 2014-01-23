#ifdef gosolve

int res;

bool known[100];
vector<int> unk;

class BlurredDartboard {
public:
	int minThrows(vector <int> points, int P) {
		res = usingBest(points, P);
		int sum = 0;
		for (int i = 0; i < (int)unk.size(); i++)
			sum += unk[i];

		if ( sum) {
			int k = P / sum;
			sum *= k;
			k *= unk.size();

			cout << k << " " << sum << endl;

			int kk = 0, sm = 0;
			for (int i = 0; sum + sm < P && i < (int)unk.size(); i++) {
				sm += unk[i];
				kk++;
			}

			res = min(res, kk+k);
			res = min(res, k+usingBest(points, P - sum));
		}

		return res;
	}

	int usingBest(vector<int> p, int P) {
		int best = 0;
		for (int i = 0; i < (int)p.size(); i++) {
			best = max(best, p[i]);
			known[p[i]] = true;
		}

		unk.clear();
		for (int i = 1; i <= p.size(); i++)
			if (!known[i])
				unk.pb(i);
		sort(unk.begin(), unk.end());
		if (unk.size())
			best = max(best, unk[0]);
		return (P + best - 1) / best;
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
		cout << "Testing BlurredDartboard (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1364743080;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BlurredDartboard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = {0, 3, 4, 0, 0};
				int P = 8;
				_expected = 2;
				_received = _obj.minThrows(vector <int>(points, points+sizeof(points)/sizeof(int)), P); break;
			}
			case 1:
			{
				int points[] = {0, 0, 0, 0, 0};
				int P = 15;
				_expected = 5;
				_received = _obj.minThrows(vector <int>(points, points+sizeof(points)/sizeof(int)), P); break;
			}
			case 2:
			{
				int points[] = {4, 7, 8, 1, 3, 2, 6, 5};
				int P = 2012;
				_expected = 252;
				_received = _obj.minThrows(vector <int>(points, points+sizeof(points)/sizeof(int)), P); break;
			}
			case 3:
			{
				int points[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0};
				int P = 2012;
				_expected = 307;
				_received = _obj.minThrows(vector <int>(points, points+sizeof(points)/sizeof(int)), P); break;
			}
			case 4:
			{
				int points[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0};
				int P = 1000000000;
				_expected = 84656087;
				_received = _obj.minThrows(vector <int>(points, points+sizeof(points)/sizeof(int)), P); break;
			}
			case 5:
			{
				int points[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				int P = 1274;
				_expected = 50;
				_received = _obj.minThrows(vector <int>(points, points+sizeof(points)/sizeof(int)), P); break;
			}
			/*case 6:
			{
				int points[] = ;
				int P = ;
				_expected = ;
				_received = _obj.minThrows(vector <int>(points, points+sizeof(points)/sizeof(int)), P); break;
			}*/
			/*case 7:
			{
				int points[] = ;
				int P = ;
				_expected = ;
				_received = _obj.minThrows(vector <int>(points, points+sizeof(points)/sizeof(int)), P); break;
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
