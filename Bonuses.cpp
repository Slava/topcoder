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

class Bonuses {
	public:
	vector <int> getDivision(vector <int> points) {
		int n = (int)points.size(), sum = 0, all = 100;
		vector<pair<int,int> > a;
		for (int i = 0; i < (int)points.size(); i++) {
			a.pb(mp(-points[i], i));
			sum += points[i];
		}
		sort (a.begin(), a.end());
		vector<int> get(points.size());
		for (int i = 0; i < n; i++) {
			get[i] = 100 * points[i] / sum;
			all -= get[i];
		}

		for (int i = 0; i < all; i++)
			get[a[i].second]++;
		return get;
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
		cout << "Testing Bonuses (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1338196216;
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
		Bonuses _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = {1,2,3,4,5};
				int __expected[] = { 6,  13,  20,  27,  34 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 1:
			{
				int points[] = {5,5,5,5,5,5};
				int __expected[] = { 17,  17,  17,  17,  16,  16 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 2:
			{
				int points[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
				                255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470};
				int __expected[] = { 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			/*case 3:
			{
				int points[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int points[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int points[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
