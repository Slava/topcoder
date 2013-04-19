#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

vector<string> g;
int N, M, n, u[100], U[100];

void sfd(int v) {
	U[v] = 1;
	for (int i = 0; i < n; i++)
		if (g[i][v] == 'Y' && !U[i])
			sfd(i);
}
void dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < n; i++)
		if (g[v][i] == 'Y' && !u[i])
			dfs(i);
}

class GogoXMarisaKirisima {
public:
	int solve(vector <string> choices) {
		g = choices;
		n = g.size();
		dfs(0);
		sfd(n-1);

		for (int i = 0; i < n; i++)
			u[i] &= U[i], N += u[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				M += (g[i][j] == 'Y') & u[i] & u[j];
		printf("%d %d\n", N, M);
		if (N < 2)return 0;
		return M - N + 2;
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
		cout << "Testing GogoXMarisaKirisima (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1328296600;
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
		GogoXMarisaKirisima _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string choices[] = {"NYN"
				                   ,"YNY"
				                   ,"NNN"};
				_expected = 2;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 1:
			{
				string choices[] = {"NNY"
				                   ,"YNY"
				                   ,"YNN"};
				_expected = 2;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 2:
			{
				string choices[] = {"NN"
				                   ,"NN"};
				_expected = 0;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 3:
			{
				string choices[] = {"NYYY"
				                   ,"NNNY"
				                   ,"NNNY"
				                   ,"NNNN"};
				_expected = 3;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			/*case 4:
			{
				string choices[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string choices[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string choices[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
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
