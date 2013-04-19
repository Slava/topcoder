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

long long st[100];
int nn;

void push(long long x) {
	st[nn++] = x;
}

long long  pop() {
	if (nn)return st[--nn];
	else
		return 0;
}

vector<int> a;
int N, x, n;
class Suminator {
	public:
	long long doit() {
		nn = 0;
		memset(st,0,sizeof st);
		for (int i = 0; i < n; i++)
			if (a[i])
				push(a[i]);
			else {
				long long r = pop(), l = pop();
				push(l+r);
			}
		return pop();
	}
	int findMissing(vector <int> program, int wantedResult) {
		a = program;
		N = wantedResult;
		n = (int)a.size();

		for (int i = 0; i < n; i++)
			if (a[i] == -1)
				x = i;

		a[x] = 0;
		long long res;
		res = doit();
		cout << res << endl;
		if (res == wantedResult)
			return 0;
		cout << "put 1" << endl;
		a[x] = 1;
		res = doit();
		cout << res << endl;
		a[x] = wantedResult-res+1;
		cout << "put ";
		cout << a[x] << endl;
		if (a[x] < 0)
			return -1;
		res = doit();
		cout << res << endl;
		if (res == wantedResult)
			return a[x];
		cout << res << endl;
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
		cout << "Testing Suminator (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1345684233;
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
		Suminator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int program[] = {7,-1,0};
				int wantedResult = 10;
				_expected = 3;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 1:
			{
				int program[] = {100, 200, 300, 0, 100, -1};
				int wantedResult = 600;
				_expected = 0;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 2:
			{
				int program[] = {-1, 7, 3, 0, 1, 2, 0, 0};
				int wantedResult = 13;
				_expected = 0;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 3:
			{
				int program[] = {-1, 8, 4, 0, 1, 2, 0, 0};
				int wantedResult = 16;
				_expected = -1;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 4:
			{
				int program[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
				int wantedResult = 1000000000;
				_expected = -1;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 5:
			{
				int program[] = {7, -1, 3, 0};
				int wantedResult = 3;
				_expected = -1;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			case 6:
			{
				int program[] = {2,-1, 0};
				int wantedResult = 3;
				_expected = 1;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}
			/*case 7:
			{
				int program[] = ;
				int wantedResult = ;
				_expected = ;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
			}*/
			/*case 8:
			{
				int program[] = ;
				int wantedResult = ;
				_expected = ;
				_received = _obj.findMissing(vector <int>(program, program+sizeof(program)/sizeof(int)), wantedResult); break;
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
