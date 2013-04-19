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

int sumRow[3], sumCol[3], res, sum;
bool u[9];
vector<int> a;

void go(int x, int y) {
	if (y == 3)
		go(x+1, 0);
	else if (x == 3) {
		for (int i = 0; i < 3; i++)
			if (sumRow[i] != sum || sumCol[i] != sum)
				return;
		res++;
	}
	else {
		bool was[10] = {0};
		for (int i = 0; i < 9; i++)
			if (!u[i] && !was[a[i]] && sumRow[x] + a[i] <= sum && sumCol[y] + a[i] <= sum) {
				u[i] = 1;
				sumRow[x] += a[i];
				sumCol[y] += a[i];
				go(x, y+1);
				u[i] = 0;
				sumRow[x] -= a[i];
				sumCol[y] -= a[i];
				was[a[i]] = 1;
			}
	}
}

class MNS {
	public:
	int combos(vector <int> numbers) {
		a = numbers;
		foreach(i,a)
			sum += *i;
		if (sum % 3 != 0)
			return 0;
		sum /= 3;
		go(0,0);
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
		cout << "Testing MNS (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1339774392;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MNS _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {1,2,3,3,2,1,2,2,2};
				_expected = 18;
				_received = _obj.combos(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 1:
			{
				int numbers[] = {4,4,4,4,4,4,4,4,4};
				_expected = 1;
				_received = _obj.combos(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 2:
			{
				int numbers[] = {1,5,1,2,5,6,2,3,2};
				_expected = 36;
				_received = _obj.combos(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 3:
			{
				int numbers[] = {1,2,6,6,6,4,2,6,4};
				_expected = 0;
				_received = _obj.combos(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			/*case 4:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.combos(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.combos(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.combos(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
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
