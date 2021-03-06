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

int n, res;
int done[1005];
class BigBurger {
	public:
	int maxWait(vector <int> arrival, vector <int> service) {
		n = (int)arrival.size();
		int t = 0;
		for (int i = 0; i < n; i++) {
			t = max(t, arrival[i]);
			done[i] = t;
			t += service[i];
		}

		for (int i = 0; i < n; i++) {
			res = max(res, done[i]-arrival[i]);
		}
		return res;
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
		cout << "Testing BigBurger (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1340181745;
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
		BigBurger _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int arrival[] = {3,3,9};
				int service[] = {2,15,14};
				_expected = 11;
				_received = _obj.maxWait(vector <int>(arrival, arrival+sizeof(arrival)/sizeof(int)), vector <int>(service, service+sizeof(service)/sizeof(int))); break;
			}
			case 1:
			{
				int arrival[] = {182};
				int service[] = {11};
				_expected = 0;
				_received = _obj.maxWait(vector <int>(arrival, arrival+sizeof(arrival)/sizeof(int)), vector <int>(service, service+sizeof(service)/sizeof(int))); break;
			}
			case 2:
			{
				int arrival[] = {2,10,11};
				int service[] = {3,4,3};
				_expected = 3;
				_received = _obj.maxWait(vector <int>(arrival, arrival+sizeof(arrival)/sizeof(int)), vector <int>(service, service+sizeof(service)/sizeof(int))); break;
			}
			case 3:
			{
				int arrival[] = {2,10,12};
				int service[] = {15,1,15};
				_expected = 7;
				_received = _obj.maxWait(vector <int>(arrival, arrival+sizeof(arrival)/sizeof(int)), vector <int>(service, service+sizeof(service)/sizeof(int))); break;
			}
			/*case 4:
			{
				int arrival[] = ;
				int service[] = ;
				_expected = ;
				_received = _obj.maxWait(vector <int>(arrival, arrival+sizeof(arrival)/sizeof(int)), vector <int>(service, service+sizeof(service)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int arrival[] = ;
				int service[] = ;
				_expected = ;
				_received = _obj.maxWait(vector <int>(arrival, arrival+sizeof(arrival)/sizeof(int)), vector <int>(service, service+sizeof(service)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int arrival[] = ;
				int service[] = ;
				_expected = ;
				_received = _obj.maxWait(vector <int>(arrival, arrival+sizeof(arrival)/sizeof(int)), vector <int>(service, service+sizeof(service)/sizeof(int))); break;
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
