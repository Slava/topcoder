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

struct node {
	int id, next, prev;
} nodes[100];
string ans;

class PeopleCircle {
	public:
	string order(int M, int F, int K) {
		if (M == 0)
			return string(F, 'F');
		K--;
		ans = string(F+M, 'M');
		int n = F+M;
		for (int i = 0; i < n; i++)
			nodes[i].id = i, 
			nodes[i].next = (i+1)%n,
			nodes[i].prev = (i-1+n)%n;

		int cur = 0, curn = n, curk;
		for (int i = 0; i < F; i++) {
			curk = K;
			curk %= curn;
			for (int j = 0; j < curk; j++)
				cur = nodes[cur].next;
			ans[nodes[cur].id] = 'F';
			nodes[nodes[cur].prev].next = nodes[cur].next;
			nodes[nodes[cur].next].prev = nodes[cur].prev;
			cur = nodes[cur].next;
			curn--;
		}
		return ans;
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
		cout << "Testing PeopleCircle (350.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1339573135;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 350.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PeopleCircle _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numMales = 5;
				int numFemales = 3;
				int K = 2;
				_expected = "MFMFMFMM";
				_received = _obj.order(numMales, numFemales, K); break;
			}
			case 1:
			{
				int numMales = 7;
				int numFemales = 3;
				int K = 1;
				_expected = "FFFMMMMMMM";
				_received = _obj.order(numMales, numFemales, K); break;
			}
			case 2:
			{
				int numMales = 25;
				int numFemales = 25;
				int K = 1000;
				_expected = "MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF";
				_received = _obj.order(numMales, numFemales, K); break;
			}
			case 3:
			{
				int numMales = 5;
				int numFemales = 5;
				int K = 3;
				_expected = "MFFMMFFMFM";
				_received = _obj.order(numMales, numFemales, K); break;
			}
			case 4:
			{
				int numMales = 1;
				int numFemales = 0;
				int K = 245;
				_expected = "M";
				_received = _obj.order(numMales, numFemales, K); break;
			}
			/*case 5:
			{
				int numMales = ;
				int numFemales = ;
				int K = ;
				_expected = ;
				_received = _obj.order(numMales, numFemales, K); break;
			}*/
			/*case 6:
			{
				int numMales = ;
				int numFemales = ;
				int K = ;
				_expected = ;
				_received = _obj.order(numMales, numFemales, K); break;
			}*/
			/*case 7:
			{
				int numMales = ;
				int numFemales = ;
				int K = ;
				_expected = ;
				_received = _obj.order(numMales, numFemales, K); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
