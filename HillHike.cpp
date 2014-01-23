// imslavko
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define foreach(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define all(c) c.begin(),c.end() 

long long dp[110][52][52][2];
class HillHike {
	public:
	long long numPaths(int distance, int maxHeight, vector <int> landmarks) {
		int n = (int)landmarks.size();
		dp[0][0][0][0] = 1;
		for (int i = 0; i < distance; i++)
			for (int j = 0; j <= maxHeight; j++)
				for (int k = 0; k <= n; k++)
					for (int fl = 0; fl < 2; fl++)
						if (dp[i][j][k][fl] > 0)
							for (int m = -1; m < 2; m++) {
								int h = j+m;
								if ((h == 0 && i != distance-1) || h < 0 || h > maxHeight)
									continue;
								int kk = (k!=n && landmarks[k]==h?k+1:k);
								int lf = h==maxHeight?1:fl;
								dp[i+1][h][kk][lf] += dp[i][j][k][fl];
							}
		return dp[distance][0][n][1];
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
		cout << "Testing HillHike (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1338198425;
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
		HillHike _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int distance = 5;
				int maxHeight = 2;
				int landmarks[] = {};
				_expected = 3LL;
				_received = _obj.numPaths(distance, maxHeight, vector <int>(landmarks, landmarks+sizeof(landmarks)/sizeof(int))); break;
			}
			case 1:
			{
				int distance = 2;
				int maxHeight = 45;
				int landmarks[] = {};
				_expected = 0LL;
				_received = _obj.numPaths(distance, maxHeight, vector <int>(landmarks, landmarks+sizeof(landmarks)/sizeof(int))); break;
			}
			case 2:
			{
				int distance = 5;
				int maxHeight = 2;
				int landmarks[] = {2,2};
				_expected = 1LL;
				_received = _obj.numPaths(distance, maxHeight, vector <int>(landmarks, landmarks+sizeof(landmarks)/sizeof(int))); break;
			}
			case 3:
			{
				int distance = 8;
				int maxHeight = 3;
				int landmarks[] = {2,2,3,1};
				_expected = 7LL;
				_received = _obj.numPaths(distance, maxHeight, vector <int>(landmarks, landmarks+sizeof(landmarks)/sizeof(int))); break;
			}
			case 4:
			{
				int distance = 38;
				int maxHeight = 11;
				int landmarks[] = {4,5,8,5,6};
				_expected = 201667830444LL;
				_received = _obj.numPaths(distance, maxHeight, vector <int>(landmarks, landmarks+sizeof(landmarks)/sizeof(int))); break;
			}
			/*case 5:
			{
				int distance = ;
				int maxHeight = ;
				int landmarks[] = ;
				_expected = LL;
				_received = _obj.numPaths(distance, maxHeight, vector <int>(landmarks, landmarks+sizeof(landmarks)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int distance = ;
				int maxHeight = ;
				int landmarks[] = ;
				_expected = LL;
				_received = _obj.numPaths(distance, maxHeight, vector <int>(landmarks, landmarks+sizeof(landmarks)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int distance = ;
				int maxHeight = ;
				int landmarks[] = ;
				_expected = LL;
				_received = _obj.numPaths(distance, maxHeight, vector <int>(landmarks, landmarks+sizeof(landmarks)/sizeof(int))); break;
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
