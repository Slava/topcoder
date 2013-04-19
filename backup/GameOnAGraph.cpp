#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)
#define out(x) cerr<<#x<<endl;for(int I=0;I<x.size();I++){for(int J=0;J<x.size();J++)cerr<<x[I][J]<<" ";cerr<<endl;}

typedef vector<vector<int> > matrix;

#define mod 1000000009

matrix operator *(matrix a, matrix b) {
	matrix c(a.size(), vector<int>(a.size(), 0));
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a.size(); j++)
			for (int k = 0; k < a.size(); k++)
				c[i][j] = (c[i][j] + (a[i][k] * 1LL * b[k][j]) % mod) % mod;
	return c;
}

matrix init(int sz) {
	matrix a(sz, vector<int>(sz, 0));
	for (int i = 0; i < sz; i++)
		a[i][i] = 1;
	return a;
}

matrix pow(matrix a, int n) {
	matrix res = init(a.size());

	while (n > 0) {
		if (n&1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}

	return res;
}

class GameOnAGraph {
public:
	vector <int> getMarks(vector <string> adj, string colors, string marks, int N) {
		matrix W, B; W = B = matrix(adj.size(), vector<int>(adj.size(), 0));
		for (int i = 0; i < (int)colors.size(); i++)
			if (colors[i] == 'W')
				B[i][i] = 1;
			else W[i][i] = 1;

		for (int i = 0; i < (int)adj.size(); i++)
			for (int j = 0; j < (int)adj.size(); j++)
				if (adj[i][j] == '1')
					if (colors[i] == 'W')
						W[j][i] = 1;
					else B[j][i] = 1;

		matrix A = pow(B*W, N/2);
		if (N&1)
			A = A * B;


		vector<int> res;
		for (int i = 0; i < (int)adj.size(); i++) {
			long long cur = 0;
			for (int j = 0; j < (int)adj.size(); j++)
				cur = (cur + (marks[j]-'0'+0LL)*A[j][i]) % mod;
			res.push_back(cur);
		}
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
		cout << "Testing GameOnAGraph (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1328791189;
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
		GameOnAGraph _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string adj[] = {"0110","1000","1000","0000"};
				string colors = "WBBW";
				string marks = "1000";
				int N = 1;
				int __expected[] = {1, 1, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMarks(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), colors, marks, N); break;
			}
			case 1:
			{
				string adj[] = {"00000","00000","00000","00000","00000"};
				string colors = "BBWWW";
				string marks = "99999";
				int N = 1;
				int __expected[] = {0, 0, 9, 9, 9 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMarks(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), colors, marks, N); break;
			}
			case 2:
			{
				string adj[] = {"01","10"};
				string colors = "BW";
				string marks = "56";
				int N = 2;
				int __expected[] = {6, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMarks(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), colors, marks, N); break;
			}
			case 3:
			{
				string adj[] = {"010101","101010","010101","101010","010101","101010"};
				string colors = "BWBWBW";
				string marks = "012345";
				int N = 10;
				int __expected[] = {59049, 177147, 59049, 177147, 59049, 177147 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMarks(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), colors, marks, N); break;
			}
			case 4:
			{
				string adj[] = {"01","10"};
				string colors = "BW";
				string marks = "56";
				int N = 1;
				int __expected[] = {6, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMarks(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), colors, marks, N); break;
			}
			case 5:
			{
				string adj[] = {"01","10"};
				string colors = "BW";
				string marks = "56";
				int N = 0;
				int __expected[] = {5, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMarks(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), colors, marks, N); break;
			}
			/*case 6:
			{
				string adj[] = ;
				string colors = ;
				string marks = ;
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMarks(vector <string>(adj, adj+sizeof(adj)/sizeof(string)), colors, marks, N); break;
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
