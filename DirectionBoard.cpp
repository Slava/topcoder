#ifdef gosolve

namespace MCMF {
	const int N = 520;
	struct edge {
		int x, y, cost;
		int f, c;
	}a[N*N];
	int n, m, inf = (1 << 30);
	int d[N], u[N], phi[N], from[N];
	vector<int> g[N];

	void init() {
		n = m = 0; memset(d,0,sizeof d);memset(u,0,sizeof u);memset(phi, 0, sizeof phi); memset(from, 0, sizeof from);
		for (int i = 0; i < N; i++)
			g[i].clear();
	}

	void add_edge (int x, int y, int z, int c) {
		//cerr << "add edge " << x << " to " << y << " cost  " << z << " capacity " <<c << endl;
		a[m].x = x; a[m].y = y; a[m].cost = z; a[m].c = c; a[m].f = 0; m++;
		g[x].pb(m - 1);
		a[m].x = y; a[m].y = x; a[m].cost = -z; a[m].c = 0; a[m].f = 0; m++;
		g[y].pb(m - 1);
	}

	bool dijkstra (int s, int t) {
		for (int i = 0; i < n; i++)
			u[i] = 0, d[i] = inf, from[i] = -1;
		d[s] = 0;
		while (true) {
			int v = -1;
			for (int i = 0; i < n; i++) 
				if (!u[i] && (v == -1 || d[v] > d[i]))
					v = i;
				if (v == -1 || d[v] == inf)
					break;
				u[v] = 1;
				for (int i = 0; i < g[v].size(); i++) {
					int to = g[v][i];
					int x = v, y = a[to].y, z = a[to].cost,
					f = a[to].f, c = a[to].c;
					if (c - f <= 0)
						continue;
					if (d[y] > d[x] + phi[x] - phi[y] + z) {
						d[y] = d[x] + phi[x] - phi[y] + z;
						from[y] = to;
					}
				}
			}
			return u[t];
		}

		void fordbellman(int s) {
			for (int i = 0; i < n; i++)
				phi[i] = inf;
			phi[s] = 0;

			for (int k = 0; k < n; k++)
				for (int i = 0; i < m; i++)
					if (phi[a[i].y] > phi[a[i].x] + a[i].cost && a[i].c > 0) {
						phi[a[i].y] = phi[a[i].x] + a[i].cost;
					}
				}

				int mincost_maxflow (int s, int t) {
					int flow, cost;
					flow = cost = 0;
					for (int i = 0; i < n; i++)
						phi[i] = 0;
					while (true) {
						if (!dijkstra(s, t))
							break;
						for (int i = 0; i < n; i++)
							phi[i] += d[i];
						int v = t, mx = inf, u, k;
						for (;v != s; v = u) {
							k = from[v];
							u = a[k].x;
							mx = min(mx, a[k].c - a[k].f);
						}

						for (v = t; v != s; v = u) {
							k = from[v];
							u = a[k].x;
							cost += a[k].cost * mx;
							a[k].f += mx;
							a[k^1].f -= mx;
						}
						flow += mx;
					}
					return cost;
				}
			}

int N, M;

int to(int x, int y, char d) {
	switch(d) {
		case 'U':
			x--;
			if (x == -1)
				x = N-1;
			break;
		case 'D':
			x++;
			if (x == N)
				x = 0;
			break;
		case 'L':
			y--;
			if (y == -1)
				y = M-1;
			break;
		case 'R':
			y++;
			if (y == M)
				y = 0;
			break;
		default:
			cerr << "FAIL " << x << " " << y << " " << d << endl;
	}
	return x * M + y;
}

int to(int from, char d) {
	return to(from/M,from%M,d);
}

int res;
class DirectionBoard {
public:
	int getMinimum(vector <string> board) {
		N = (int)board.size();
		M = (int)board[0].size();

MCMF::init();
		MCMF::n = N*M*2+2;
		int S = N*M*2;
		int T = S+1;

		for (int i = 0; i < N*M; i++) {
			MCMF::add_edge(S,i,0,1);
			MCMF::add_edge(i+N*M,T,0,1);
		}

		string allD = "UDLR";
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				for (int k = 0; k < 4; k++) {
					MCMF::add_edge(i*M+j,N*M+to(i,j,allD[k]),board[i][j] != allD[k],1);
					//cerr << i << " " << j << "  using " << allD[k] << " to " << to(i,j,allD[k])/M << " " << to(i,j,allD[k])%M << "  cost " << (allD[k] != board[i][j]) << endl; ;
				}

		return MCMF::mincost_maxflow(S,T);
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
		cout << "Testing DirectionBoard (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361640679;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DirectionBoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"RRRD",
				                  "URDD",
				                  "UULD",
				                  "ULLL"};
				_expected = 0;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"RRRD",
				                  "URLL",
				                  "LRRR"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"RRD",
				                  "URD",
				                  "ULL"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"ULRLRD",
				                  "UDDLRR"};
				_expected = 4;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"UDLRLDLD",
				                  "DLDLLDLR",
				                  "LLLLLDLD",
				                  "UUURRRDD"};
				_expected = 9;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUUDDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "RRRDLDURDURUDDR"};
				_expected = 73;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"LRRR"};
				_expected = 1;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				std::vector<string> v;
				for (int i = 0; i < 15; i++) {
					string c = "";
					for (int j = 0; j < 15; j++)
						c += "R";
					v.pb(c);
				}
				_expected = 0;
				_received = _obj.getMinimum(v); break;
			}
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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

#endif
// imslavko
