#ifdef gosolve

bool m[200][200];
const int mid = 100;

vector <string> res;
class FallingCoconuts {
public:
	vector <string> harvest(vector <int> drops) {
		int leftmost = 199;
		int rightmost = 0;
		int highest = 0;

		for (int i = 0; i < (int)drops.size(); i++) {
			int x = mid + drops[i];
			int y = mid;

			while (y > 0) {
				if (!m[y-1][x])
					y--;
				else if (!m[y-1][x+1])
					y--, x++;
				else if (!m[y-1][x-1])
					y--, x--;
				else
					break;
			}
			m[y][x] = true;
			highest = max(highest, y+1);
			leftmost = min(leftmost, x);
			rightmost = max(rightmost, x+1);
		}

		for (int i = 0; i < highest; i++) {
			string s = "";
			for (int j = leftmost; j < rightmost; j++)
				s += "-O"[m[i][j]];
			res.pb(s);
		}

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
		cout << "Testing FallingCoconuts (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1359440860;
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
		FallingCoconuts _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int drops[] = {8, 9, 10, 11, 12, 8, 12, 10};
				string __expected[] = {"OOOOOOO", "---O---" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.harvest(vector <int>(drops, drops+sizeof(drops)/sizeof(int))); break;
			}
			case 1:
			{
				int drops[] = {5, 20, 5, 20, 5, 6, 7};
				string __expected[] = {"OOOOO-----------OO" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.harvest(vector <int>(drops, drops+sizeof(drops)/sizeof(int))); break;
			}
			case 2:
			{
				int drops[] = {6, 8, 10, 7, 9, 8, 8, 8, 8, 8};
				string __expected[] = {"OOOOOO", "-OOO--", "--O---" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.harvest(vector <int>(drops, drops+sizeof(drops)/sizeof(int))); break;
			}
			case 3:
			{
				int drops[] = {0, 0, 0, 0};
				string __expected[] = {"OOO", "-O-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.harvest(vector <int>(drops, drops+sizeof(drops)/sizeof(int))); break;
			}
			case 4:
			{
				int drops[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 
				              5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
				string __expected[] = {"OOOOOOOOOOOO", "-OOOOOOOOOO-", "--OOOOOOOO--", "---OOOOOO---", "----OOOO----", "-----OO-----" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.harvest(vector <int>(drops, drops+sizeof(drops)/sizeof(int))); break;
			}
			/*case 5:
			{
				int drops[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.harvest(vector <int>(drops, drops+sizeof(drops)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int drops[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.harvest(vector <int>(drops, drops+sizeof(drops)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int drops[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.harvest(vector <int>(drops, drops+sizeof(drops)/sizeof(int))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE

#endif
// imslavko
