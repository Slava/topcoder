// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You might have played the game called Memoria. In this game, there is a board consisting of N rows containing M cells each. Each of the cells has a symbol on its back. Each symbol occurs on exactly two cells on the board.

A move means turning a pair of cells one by one to see the symbols behind them. When the symbols differ, both of the cells are turned on their faces, thus hiding the symbols again. The player should remember the symbols. If the symbols on the backs of the turned cells coincide, the cells stay that way, i.e., don't turn back again. As soon as after some move all the cells on the board are turned (such that all the symbols are simultaneously visible), the game ends.

Manao has a perfect memory, so when he sees the symbol behind some cell, he remembers it forever. Manao is trying to finish the game in the least expected number of moves. Find the expected number of moves he will need to accomplish this.

DEFINITION
Class:PerfectMemory
Method:getExpectation
Parameters:int, int
Returns:double
Method signature:double getExpectation(int N, int M)


NOTES
-The board Manao plays on is generated as follows. The same set of (N * M) / 2 symbols is used for each generation. The board contents are chosen uniformly among all valid N x M boards.
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-M will be between 1 and 50, inclusive.
-N * M will be even.


EXAMPLES

0)
1
2

Returns: 1.0

There are only two cells on the board, so the game always ends in one move.

1)
2
2

Returns: 2.6666666666666665

There are four cells. The game may flow in two possible scenarios:
1) In the first move, Manao turns two cells with equal symbols. The game ends in two moves then and the probability of such a first move is 1/3.
2) In the first move, Manao turns two cells with different symbols. Then he finishes the game in three moves and the probability of such a first move is 2/3.
The overall expected number of moves is 1/3 * 2 + 2/3 * 3 = 8/3.

2)
2
3

Returns: 4.333333333333334



3)
4
4

Returns: 12.392984792984793



*/
// END CUT HERE
#line 69 "PerfectMemory.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

#define FIRST 0
#define SECOND 1
#define NN  50*25
bool u[NN][NN][2];
double dp[NN][NN][2];

double expected(int total, int seen, bool turn) {
//	printf(">> %d %d %d\n", total, seen, turn);fflush(stdout);
	double &res = dp[total][seen][turn];
	if (u[total][seen][turn])
		return res;
	u[total][seen][turn] = 1;
	res = 0;

	if (!total)
		return res;
	int unseen = 2*total - seen;

	if (turn == FIRST) {
		// p1 = open card, that already was
		// p2 = open new card
		double p1 = seen / (unseen + .0);
		double p2 = 1 - p1;

		if (seen > 0)
			res += p1 * (expected(total-1, seen-1, FIRST) + 1);
		if (unseen > seen)
			res += p2 * expected(total, seen+1, SECOND);
	} else {
		// p1 = we open card equal to just opened
		// p2 = card that was befoure
		// p3 = card new to us
		double p1 = 1. / unseen;
		double p2 = (seen-1.) / unseen;
		double p3 = 1 - p1 - p2;

		res += p1 * (1 + expected(total-1, seen-1, FIRST));
		if (seen > 1)
			res += p2 * (2 + expected(total-1, seen-1, FIRST));
		if (unseen > seen)
			res += p3 * (1 + expected(total, seen+1, FIRST));
	}

	return res;
}

class PerfectMemory {
public:
	double getExpectation(int N, int M) {
		return expected(N*M/2, 0, FIRST);
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
		cout << "Testing PerfectMemory (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1328277555;
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
		PerfectMemory _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				int M = 2;
				_expected = 1.0;
				_received = _obj.getExpectation(N, M); break;
			}
			case 1:
			{
				int N = 2;
				int M = 2;
				_expected = 2.6666666666666665;
				_received = _obj.getExpectation(N, M); break;
			}
			case 2:
			{
				int N = 2;
				int M = 3;
				_expected = 4.333333333333334;
				_received = _obj.getExpectation(N, M); break;
			}
			case 3:
			{
				int N = 4;
				int M = 4;
				_expected = 12.392984792984793;
				_received = _obj.getExpectation(N, M); break;
			}
			/*case 4:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.getExpectation(N, M); break;
			}*/
			/*case 5:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.getExpectation(N, M); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.getExpectation(N, M); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
