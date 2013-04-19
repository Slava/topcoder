// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You may remember an old computer game called "The Incredible Machine". It was a game where you could simulate simple processes like balls falling, lasers shooting, or cats pursuing mice.
Manao is faced with the following problem in this game.

The game is 2-dimensional. To make solving the problem easier, Manao introduced the cartesian coordinates on the screen. The OX axis goes from left to right and coincides with the ground. The OY axis goes from bottom to top.

There are N horizontal platforms mounted at different heights. The length of the i-th platform is platformLength[i] and it is mounted at point (platformMount[i], i + 1). Each platform can be moved horizontally in such a way that it does not disconnect from its mount, i.e., the mount resides between its ends or on one of them. In other words, the leftmost possible position of the i-th platform is when its left end is at (platformMount[i] - platformLength[i], i + 1) and the rightmost position is when its right end is at (platformMount[i] + platformLength[i], i + 1). The platforms may only be moved by integer distances, so both left and right ends of a platform are always located at points with integer coordinates.

Several balls will simultaneously fall downwards to the ground from a height that is above all platforms. All balls will fall vertically and the i-th of them will fall at X-coordinate balls[i]. The balls are very small and can be considered as points. Manao should set the platforms' placement in such a way that no ball falls on a platform. Falling on an end of a platform counts as falling on a platform. Manao is not allowed to move the platforms once the balls start falling.

Count the number of ways to place the platforms so that all of the balls miss them. Return this number modulo 1,000,000,009. Two placements are different if there's a platform that has different positions in these placements.

DEFINITION
Class:YetAnotherIncredibleMachine
Method:countWays
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls)


CONSTRAINTS
-platformMount will contain between 1 and 50 elements, inclusive.
-Each element of platformMount will be between -10000 and 10000, inclusive.
-platformLength will contain the same number of elements as platformMount.
-Each element of platformLength will be between 1 and 10000, inclusive.
-balls will contain between 1 and 50 elements, inclusive.
-Each element of balls will be between -10000 and 10000, inclusive.
-All elements of balls will be distinct.


EXAMPLES

0)
{7}
{10}
{3,4}

Returns: 3

A platform of length 10 is mounted at point (7, 1). Two balls will fall at coordinates 3 and 4. There are three placements of the platform which let the ball miss it: setting the platform's left end at X-coordinate 5, 6 and 7.

1)
{1,4}
{3,3}
{2,7}

Returns: 1

The only placement which ensures that balls land aside the platforms is when platform 0's right end is at point (1, 1) and platform 1's left end is at (3, 2).

2)
{4,4,4}
{10,9,8}
{1,100}

Returns: 27

There are 3 possible placements for each of the platforms.

3)
{0}
{1}
{0}

Returns: 0

There is no way to move the platform away from the ball's trajectory.

4)
{100, -4215, 251}
{400, 10000, 2121}
{5000, 2270, 8512, 6122}

Returns: 250379170



*/
// END CUT HERE
#line 83 "YetAnotherIncredibleMachine.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

class YetAnotherIncredibleMachine {
public:
	int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) {
		int platformN = (int)platformMount.size(), ballsN = (int)balls.size();
		int ans = 1;
		for (int i = 0; i < platformN; i++) {
			int l = platformMount[i] - platformLength[i] - 1, r = platformMount[i] + platformLength[i] + 1;
			for (int j = 0; j < ballsN; j++)
				if (balls[j] == platformMount[i])
					l = r = platformMount[i];
				else if (balls[j] < platformMount[i])
					l = max(l, balls[j]);
				else r = min(r, balls[j]);
			int pos = max(r - l - platformLength[i] - 1, 0);
//			printf("%d bet(%d,%d) len %d %d\n", platformMount[i], l, r, platformLength[i], pos);
			ans = (ans * 1LL * pos) % 1000000009;
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
		cout << "Testing YetAnotherIncredibleMachine (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1328279254;
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
		YetAnotherIncredibleMachine _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int platformMount[] = {7};
				int platformLength[] = {10};
				int balls[] = {3,4};
				_expected = 3;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}
			case 1:
			{
				int platformMount[] = {1,4};
				int platformLength[] = {3,3};
				int balls[] = {2,7};
				_expected = 1;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}
			case 2:
			{
				int platformMount[] = {4,4,4};
				int platformLength[] = {10,9,8};
				int balls[] = {1,100};
				_expected = 27;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}
			case 3:
			{
				int platformMount[] = {0};
				int platformLength[] = {1};
				int balls[] = {0};
				_expected = 0;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}
			case 4:
			{
				int platformMount[] = {100, -4215, 251};
				int platformLength[] = {400, 10000, 2121};
				int balls[] = {5000, 2270, 8512, 6122};
				_expected = 250379170;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}
			/*case 5:
			{
				int platformMount[] = ;
				int platformLength[] = ;
				int balls[] = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int platformMount[] = ;
				int platformLength[] = ;
				int balls[] = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int platformMount[] = ;
				int platformLength[] = ;
				int balls[] = ;
				_expected = ;
				_received = _obj.countWays(vector <int>(platformMount, platformMount+sizeof(platformMount)/sizeof(int)), vector <int>(platformLength, platformLength+sizeof(platformLength)/sizeof(int)), vector <int>(balls, balls+sizeof(balls)/sizeof(int))); break;
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
