#ifdef gosolve

double res;
class LateProfessor {
public:
	double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) {
		if (worstArrival == bestArrival) {
			res = 0;

			for (int i = waitTime; i <= worstArrival; i += waitTime + walkTime) {
				if (bestArrival > i && bestArrival <= i + walkTime - lateTime) {
					res = 1;
				}
			}
			return res;
		}

		for (double bs = waitTime; bs <= worstArrival; bs += waitTime + walkTime) {
			double be = bs + walkTime - lateTime;
			double intersectionS = max(bs, (double)bestArrival);
			double intersectionE = min(be, (double)worstArrival);

			if (intersectionS < intersectionE)
				res += intersectionE - intersectionS;

			//printf("B = [%.3lf,%.3lf), prof = [%d,%d], intersection = [%.3lf,%.3lf]\n", bs, be, bestArrival, worstArrival, intersectionS, intersectionE);
		}

		res /= (worstArrival - bestArrival);
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
		cout << "Testing LateProfessor (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1359471967;
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
		LateProfessor _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int waitTime = 20;
				int walkTime = 30;
				int lateTime = 10;
				int bestArrival = 0;
				int worstArrival = 50;
				_expected = 0.4;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 1:
			{
				int waitTime = 20;
				int walkTime = 30;
				int lateTime = 10;
				int bestArrival = 30;
				int worstArrival = 100;
				_expected = 0.42857142857142855;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 2:
			{
				int waitTime = 20;
				int walkTime = 40;
				int lateTime = 50;
				int bestArrival = 0;
				int worstArrival = 300;
				_expected = 0.0;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 3:
			{
				int waitTime = 101;
				int walkTime = 230;
				int lateTime = 10;
				int bestArrival = 654;
				int worstArrival = 17890;
				_expected = 0.6637270828498492;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 4:
			{
				int waitTime = 20;
				int walkTime = 30;
				int lateTime = 10;
				int bestArrival = 90;
				int worstArrival = 90;
				_expected = 1.0;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 5:
			{
				int waitTime = 1000;
				int walkTime = 600;
				int lateTime = 1;
				int bestArrival = 17000;
				int worstArrival = 17000;
				_expected = 0.0;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			case 6:
			{
				int waitTime = 20;
				int walkTime = 30;
				int lateTime = 10;
				int bestArrival = 10;
				int worstArrival = 10;
				_expected = 0.0;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}
			/*case 7:
			{
				int waitTime = ;
				int walkTime = ;
				int lateTime = ;
				int bestArrival = ;
				int worstArrival = ;
				_expected = ;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
			}*/
			/*case 8:
			{
				int waitTime = ;
				int walkTime = ;
				int lateTime = ;
				int bestArrival = ;
				int worstArrival = ;
				_expected = ;
				_received = _obj.getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival); break;
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

#endif
// imslavko
