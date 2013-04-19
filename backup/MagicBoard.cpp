#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

const int NN = 50*50*2+100;
int n, m, N;
int a[51][51], g[NN][NN];
int p[NN];

class MagicBoard {
public:
	string ableToUnlock(vector <string> board) {
		n = (int)board.size();
		m = (int)board[0].size();
		if (n * m == 1)
			return "YES";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (board[i][j] == '#')
					a[i][j] = N++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (board[i][j] == '#') {
					for (int k = 0; k < n; k++)
						if (k != i && board[k][j] == '#')
							g[a[i][j]*2][a[k][j]*2+1] = 
							g[a[k][j]*2][a[i][j]*2+1] = 1;
					for (int k = 0; k < m; k++)
						if (k != j && board[i][k] == '#')
							g[a[i][j]*2][a[i][k]*2+1] = 
							g[a[i][k]*2][a[i][j]*2+1] = 1;
				}
		for (int i = 0; i < N * 2; i++)
			for (int j = 0; j < N * 2; j++)
				p[i] += g[i][j];
		for (int i = 0; i < N * 2; i++)
			if (p[i] & 1)
				printf("%d\n", i);
		return "NO";
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
		cout << "Testing MagicBoard (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1329586124;
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
		MagicBoard _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"##",
				                  ".#"};
				_expected = "YES";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"#.",
				                  ".#"};
				_expected = "NO";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"##",
				                  "##",
				                  "##"};
				_expected = "YES";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"###",
				                  "###",
				                  "###"};
				_expected = "NO";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"###",
				                  "..#",
				                  "###",
				                  "#..",
				                  "###"};
				_expected = "NO";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"................",
				                  ".######..######.",
				                  ".######..######.",
				                  ".##......##..##.",
				                  ".##......##..##.",
				                  ".######..######.",
				                  ".######..######.",
				                  ".....##..##..##.",
				                  ".....##..##..##.",
				                  ".######..######.",
				                  ".######..######.",
				                  "................"};
				_expected = "YES";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"#"};
				_expected = "YES";
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.ableToUnlock(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
