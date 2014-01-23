#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

class FindingSquareInTable {
public:
	int findMaximalSquare(vector <string> table) {
		int ans = -1;
		int n = (int)table.size(), m = (int)table[0].size();
		int MAX = 10;
		for (int i = 0; i < n; i++)	
			for (int j = 0; j < m; j++)
				for (int di = -MAX; di <= MAX; di++)
					for (int dj = -MAX; dj <= MAX; dj++) {
						int cur = 0, x = i, y = j;
						while (x < n && x >= 0 && y < m && y >= 0) {
							cur = cur * 10 + table[x][y] - '0';
							x += di; y += dj;
							int sqroot = sqrtl(cur);
							if (sqroot * sqroot == cur && cur > ans)
								ans = cur;
							if (!di && !dj)
								break;
						}
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
		cout << "Testing FindingSquareInTable (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1330788661;
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
		FindingSquareInTable _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string table[] = {"123",
				                  "456"};
				_expected = 64;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 1:
			{
				string table[] = {"00000",
				                  "00000",
				                  "00200",
				                  "00000",
				                  "00000"};
				_expected = 0;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 2:
			{
				string table[] = {"3791178",
				                  "1283252",
				                  "4103617",
				                  "8233494",
				                  "8725572",
				                  "2937261"};
				_expected = 320356;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 3:
			{
				string table[] = {"135791357",
				                  "357913579",
				                  "579135791",
				                  "791357913",
				                  "913579135"};
				_expected = 9;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 4:
			{
				string table[] = {"553333733",
				                  "775337775",
				                  "777537775",
				                  "777357333",
				                  "755553557",
				                  "355533335",
				                  "373773573",
				                  "337373777",
				                  "775557777"};
				_expected = -1;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 5:
			{
				string table[] = {"257240281",
				                  "197510846",
				                  "014345401",
				                  "035562575",
				                  "974935632",
				                  "865865933",
				                  "684684987",
				                  "768934659",
				                  "287493867"};
				_expected = 95481;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 6:
			{
				string table[] = {"40000009"};
				_expected = 9000000;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			/*case 7:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.findMaximalSquare(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
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
