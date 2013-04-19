// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Manao is playing a new game called Reflections. The goal of the game is transferring an artifact in 3-dimensional space from point (0, 0, 0) to point (X, Y, Z). There are two types of moves in the game:

1) The player can move the artifact by 1 unit in the direction of any coordinate axis. So, using this type of move, from point (a, b, c) the artifact can be moved to points (a + 1, b, c), (a - 1, b, c), (a, b + 1, c), (a, b - 1, c), (a, b, c + 1) or (a, b, c - 1).

2) The player can reflect the artifact against any one of the given planes. The reflection works as follows: the artifact disappears at its position before the reflection and appears on the other side of the plane at such a place that the line connecting the old and new positions is perpendicular to the plane and the old and new positions are equidistant from the plane. Reflection against each particular plane can be performed at most once during the game.

The planes are given as vector <int>s mirrorX, mirrorY and mirrorZ. mirrorX[i] corresponds to a plane perpendicular to the X axis with coordinate X = mirrorX[i]. mirrorY and mirrorZ contain planes perpendicular to the Y and Z axis in the same fashion. The target position is given in vector <int> finalPosition. finalPosition contains 3 elements, where finalPosition[0] is X, finalPosition[1] is Y and finalPosition[2] is Z.

Return the minimum possible number of moves which Manao will need to transfer the artifact.

DEFINITION
Class:Reflections
Method:minimumMoves
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:long long
Method signature:long long minimumMoves(vector <int> mirrorX, vector <int> mirrorY, vector <int> mirrorZ, vector <int> finalPosition)


CONSTRAINTS
-finalPosition will contain exactly 3 elements.
-Each element of finalPosition will be between -1,000,000,000 and 1,000,000,000, inclusive.
-mirrorX will contain between 0 and 20 elements, inclusive.
-Each element of mirrorX will be between -1,000,000,000 and 1,000,000,000, inclusive.
-All elements of mirrorX will be distinct.
-mirrorY will contain between 0 and 20 elements, inclusive.
-Each element of mirrorY will be between -1,000,000,000 and 1,000,000,000, inclusive.
-All elements of mirrorY will be distinct.
-mirrorZ will contain between 0 and 20 elements, inclusive.
-Each element of mirrorZ will be between -1,000,000,000 and 1,000,000,000, inclusive.
-All elements of mirrorZ will be distinct.


EXAMPLES

0)
{2}
{}
{}
{3, 0, 1}

Returns: 3

Manao can reflect the artifact against the only given plane, making it appear at (4, 0, 0). Afterwards, he can transfer it into the target position by two moves of the first type.

1)
{-5, 1, 4, 2, 3, 6, -6}
{}
{}
{9, 0, 0}

Returns: 2

A possible solution will be moving the artifact to (-1, 0, 0) and then reflecting it against the plane represented by mirrorX[2].

2)
{5, 8}
{}
{}
{4, 0, 0}

Returns: 4

If a reflection against a particular plane was allowed more than once, Manao could transfer the artifact in only three moves.

3)
{5}
{5}
{1, 2, 3}
{10, 12, -1}

Returns: 5

The planes perpendicular to the Z axis are of no use. After performing the reflections against the other two planes, Manao gets the artifact to point (10, 10, 0). Three more moves of the first type are required then.

4)
{8, -3, 21}
{4, 5}
{-7, -2, -1, 7, 14}
{40, -4, 31}

Returns: 10



*/
// END CUT HERE
#line 91 "Reflections.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

typedef long long ll;
class Reflections {
public:
	ll go(vector<int> M, int P) {
		int N = M.size();
		vector<long long> V[25];
		for(int i = 0; i < 1 << N; i++) {
			long long sum = 0;
			for(int j = 0; j < N; j++) if(i & 1 << j) sum += M[j] * 2ll;
			V[__builtin_popcount(i)].push_back(sum);
		}
		long long ret = abs(P);
		for(int i = 0; i <= (N + 1) / 2; i++) {
			sort(V[i].begin(), V[i].end());
			for(int j = 0; j < (int)V[i].size(); j++) {
				int pos = upper_bound(V[i].begin(), V[i].end(), V[i][j] - P) - V[i].begin();
				if(pos < (int)V[i].size()) ret = min(ret, 2 * i + abs(P - V[i][j] + V[i][pos]));
				if(pos > 0) ret = min(ret, 2 * i + abs(P - V[i][j] + V[i][pos - 1]));

				if(!i) continue;
				pos = upper_bound(V[i - 1].begin(), V[i - 1].end(), V[i][j] - P) - V[i - 1].begin();
				if(pos < (int)V[i - 1].size()) ret = min(ret, 2 * i - 1 + abs(P - V[i][j] + V[i - 1][pos]));
				if(pos > 0) ret = min(ret, 2 * i - 1 + abs(P - V[i][j] + V[i - 1][pos - 1]));
			}
		}
		return ret;
	}

	ll minimumMoves(vector <int> mirrorX, vector <int> mirrorY, vector <int> mirrorZ, vector <int> finalPosition) {
		return go(mirrorX, finalPosition[0])
			+ go(mirrorY, finalPosition[1])
			+ go(mirrorZ, finalPosition[2]);
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
		cout << "Testing Reflections (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1328281133;
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
		Reflections _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int mirrorX[] = {2};
				int mirrorY[] = {};
				int mirrorZ[] = {};
				int finalPosition[] = {3, 0, 1};
				_expected = 3LL;
				_received = _obj.minimumMoves(vector <int>(mirrorX, mirrorX+sizeof(mirrorX)/sizeof(int)), vector <int>(mirrorY, mirrorY+sizeof(mirrorY)/sizeof(int)), vector <int>(mirrorZ, mirrorZ+sizeof(mirrorZ)/sizeof(int)), vector <int>(finalPosition, finalPosition+sizeof(finalPosition)/sizeof(int))); break;
			}
			case 1:
			{
				int mirrorX[] = {-5, 1, 4, 2, 3, 6, -6};
				int mirrorY[] = {};
				int mirrorZ[] = {};
				int finalPosition[] = {9, 0, 0};
				_expected = 2LL;
				_received = _obj.minimumMoves(vector <int>(mirrorX, mirrorX+sizeof(mirrorX)/sizeof(int)), vector <int>(mirrorY, mirrorY+sizeof(mirrorY)/sizeof(int)), vector <int>(mirrorZ, mirrorZ+sizeof(mirrorZ)/sizeof(int)), vector <int>(finalPosition, finalPosition+sizeof(finalPosition)/sizeof(int))); break;
			}
			case 2:
			{
				int mirrorX[] = {5, 8};
				int mirrorY[] = {};
				int mirrorZ[] = {};
				int finalPosition[] = {4, 0, 0};
				_expected = 4LL;
				_received = _obj.minimumMoves(vector <int>(mirrorX, mirrorX+sizeof(mirrorX)/sizeof(int)), vector <int>(mirrorY, mirrorY+sizeof(mirrorY)/sizeof(int)), vector <int>(mirrorZ, mirrorZ+sizeof(mirrorZ)/sizeof(int)), vector <int>(finalPosition, finalPosition+sizeof(finalPosition)/sizeof(int))); break;
			}
			case 3:
			{
				int mirrorX[] = {5};
				int mirrorY[] = {5};
				int mirrorZ[] = {1, 2, 3};
				int finalPosition[] = {10, 12, -1};
				_expected = 5LL;
				_received = _obj.minimumMoves(vector <int>(mirrorX, mirrorX+sizeof(mirrorX)/sizeof(int)), vector <int>(mirrorY, mirrorY+sizeof(mirrorY)/sizeof(int)), vector <int>(mirrorZ, mirrorZ+sizeof(mirrorZ)/sizeof(int)), vector <int>(finalPosition, finalPosition+sizeof(finalPosition)/sizeof(int))); break;
			}
			case 4:
			{
				int mirrorX[] = {8, -3, 21};
				int mirrorY[] = {4, 5};
				int mirrorZ[] = {-7, -2, -1, 7, 14};
				int finalPosition[] = {40, -4, 31};
				_expected = 10LL;
				_received = _obj.minimumMoves(vector <int>(mirrorX, mirrorX+sizeof(mirrorX)/sizeof(int)), vector <int>(mirrorY, mirrorY+sizeof(mirrorY)/sizeof(int)), vector <int>(mirrorZ, mirrorZ+sizeof(mirrorZ)/sizeof(int)), vector <int>(finalPosition, finalPosition+sizeof(finalPosition)/sizeof(int))); break;
			}
			/*case 5:
			{
				int mirrorX[] = ;
				int mirrorY[] = ;
				int mirrorZ[] = ;
				int finalPosition[] = ;
				_expected = LL;
				_received = _obj.minimumMoves(vector <int>(mirrorX, mirrorX+sizeof(mirrorX)/sizeof(int)), vector <int>(mirrorY, mirrorY+sizeof(mirrorY)/sizeof(int)), vector <int>(mirrorZ, mirrorZ+sizeof(mirrorZ)/sizeof(int)), vector <int>(finalPosition, finalPosition+sizeof(finalPosition)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int mirrorX[] = ;
				int mirrorY[] = ;
				int mirrorZ[] = ;
				int finalPosition[] = ;
				_expected = LL;
				_received = _obj.minimumMoves(vector <int>(mirrorX, mirrorX+sizeof(mirrorX)/sizeof(int)), vector <int>(mirrorY, mirrorY+sizeof(mirrorY)/sizeof(int)), vector <int>(mirrorZ, mirrorZ+sizeof(mirrorZ)/sizeof(int)), vector <int>(finalPosition, finalPosition+sizeof(finalPosition)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int mirrorX[] = ;
				int mirrorY[] = ;
				int mirrorZ[] = ;
				int finalPosition[] = ;
				_expected = LL;
				_received = _obj.minimumMoves(vector <int>(mirrorX, mirrorX+sizeof(mirrorX)/sizeof(int)), vector <int>(mirrorY, mirrorY+sizeof(mirrorY)/sizeof(int)), vector <int>(mirrorZ, mirrorZ+sizeof(mirrorZ)/sizeof(int)), vector <int>(finalPosition, finalPosition+sizeof(finalPosition)/sizeof(int))); break;
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
