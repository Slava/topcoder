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

class PlatypusDuckAndBeaver {
	public:
	int minimumAnimals(int webbedFeet, int duckBills, int beaverTails) {
		for (int i = 0; i <= 1000; i++)
			for (int j = 0; j <= 1000; j++) {
				int wf = webbedFeet-i*2-j*4,
					db = duckBills-i,
					bt = beaverTails-j;
				int k = db;
				if (k >= 0 && k == bt && k*4 == wf)
					return i+j+k;
			}
		return -1;
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
		cout << "Testing PlatypusDuckAndBeaver (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1346515009;
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
		PlatypusDuckAndBeaver _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int webbedFeet = 4;
				int duckBills = 1;
				int beaverTails = 1;
				_expected = 1;
				_received = _obj.minimumAnimals(webbedFeet, duckBills, beaverTails); break;
			}
			case 1:
			{
				int webbedFeet = 0;
				int duckBills = 0;
				int beaverTails = 0;
				_expected = 0;
				_received = _obj.minimumAnimals(webbedFeet, duckBills, beaverTails); break;
			}
			case 2:
			{
				int webbedFeet = 10;
				int duckBills = 2;
				int beaverTails = 2;
				_expected = 3;
				_received = _obj.minimumAnimals(webbedFeet, duckBills, beaverTails); break;
			}
			case 3:
			{
				int webbedFeet = 60;
				int duckBills = 10;
				int beaverTails = 10;
				_expected = 20;
				_received = _obj.minimumAnimals(webbedFeet, duckBills, beaverTails); break;
			}
			case 4:
			{
				int webbedFeet = 1000;
				int duckBills = 200;
				int beaverTails = 200;
				_expected = 300;
				_received = _obj.minimumAnimals(webbedFeet, duckBills, beaverTails); break;
			}
			/*case 5:
			{
				int webbedFeet = ;
				int duckBills = ;
				int beaverTails = ;
				_expected = ;
				_received = _obj.minimumAnimals(webbedFeet, duckBills, beaverTails); break;
			}*/
			/*case 6:
			{
				int webbedFeet = ;
				int duckBills = ;
				int beaverTails = ;
				_expected = ;
				_received = _obj.minimumAnimals(webbedFeet, duckBills, beaverTails); break;
			}*/
			/*case 7:
			{
				int webbedFeet = ;
				int duckBills = ;
				int beaverTails = ;
				_expected = ;
				_received = _obj.minimumAnimals(webbedFeet, duckBills, beaverTails); break;
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
