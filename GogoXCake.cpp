#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

bool cake[100][100], cutter[100][100];
int N, M, n, m;

bool clear(int x, int y) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (cutter[i][j])if (!cake[i+x][j+y])
				return 0;
			else cake[i+x][j+y] = 0;
	return 1;
}

class GogoXCake {
public:
	string solve(vector <string> Cake, vector <string> Cutter) {
		N = (int)Cake.size();
		M = (int)Cake[0].size();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cake[i][j] = Cake[i][j] == '.';
		n = (int)Cutter.size();
		m = (int)Cutter[0].size();
		int I, J; I = J = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cutter[i][j] = Cutter[i][j] == '.';
				if (cutter[i][j] && I == -1)
					I = i, J = j;
			}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (i+n-I<=N && j+m-J<=M && i-I>=0 && j-J>=0 && cake[i][j])
					if(!clear(i-I,j-J))
						return "NO";
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (cake[i][j])
					return "NO";
		return "YES";
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
		cout << "Testing GogoXCake (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1328295476;
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
		GogoXCake _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cake[] = {"X.X"
				                ,"..."
				                ,"..."
				                ,"X.X"};
				string cutter[] = {".X"
				                  ,".."
				                  ,"X."};
				_expected = "YES";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 1:
			{
				string cake[] = {"..XX"
				                ,"...X"
				                ,"X..."
				                ,"XX.."};
				string cutter[] = {".."
				                  ,".."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 2:
			{
				string cake[] = {"...X..."};
				string cutter[] = {"..."};
				_expected = "YES";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 3:
			{
				string cake[] = {".X."
				                ,"X.X"
				                ,".X."};
				string cutter[] = {"."};
				_expected = "YES";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 4:
			{
				string cake[] = {"XXXXXXX"
				                ,"X.....X"
				                ,"X.....X"
				                ,"X.....X"
				                ,"XXXXXXX"};
				string cutter[] = {".X."
				                  ,"XXX"
				                  ,".X."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 5:
			{
				string cake[] = {".."
				                ,"X."
				                ,".X"};
				string cutter[] = {".."
				                  ,".X"
				                  ,"X."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 6:
			{
				string cake[] = {"X.."
				                ,".XX"
				                ,".XX"};
				string cutter[] = {".XX"
				                  ,".XX"
				                  ,"X.."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			/*case 7:
			{
				string cake[] = ;
				string cutter[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string cake[] = ;
				string cutter[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string cake[] = ;
				string cutter[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
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
