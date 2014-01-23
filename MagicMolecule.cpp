#ifdef gosolve

int res, n, need;
vector<int> magicPower;
vector<string>magicBond;
map<Int, int> memo;

int get(Int mask) {
	if (memo.count(mask))
		return memo[mask];
	int &res = memo[mask];
	res = -1;

	if (bitcount(mask) < need)
		return res;

	int badA = -1, badB;

	for (int i = 0; i < n; i++)
		if (mask & (1LL << i))
			for (int j = i + 1; j < n; j++)
				if (mask & (1LL << j))
					if (magicBond[i][j] == 'N') {
						badA = i;
						badB = j;
						break;
					}

	if (badA == -1) {
		res = 0;
		for (int i = 0; i < n; i++)
			if (mask & (1LL << i))
				res += magicPower[i];
		return res;
	}

	return res = max(get(mask ^ (1LL << badA)), get(mask ^ (1LL << badB)));
}

class MagicMolecule {
public:
	int maxMagicPower(vector <int> magicPower, vector <string> magicBond) {
		::magicBond = magicBond;
		::magicPower = magicPower;


		res = -1;
		n = (int)magicPower.size();
		for (; need * 3 < 2 * n; need++);

		return get((1LL << n) - 1);
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

int bitcount(Int n) {
	int c = 0;
	for (; n; n &= (n - 1))
		c++;
	return c;
}

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
		cout << "Testing MagicMolecule (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1361291514;
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
		MagicMolecule _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int magicPower[] = {1,2,3};
				string magicBond[] = {"NYY","YNN","YNN"};
				_expected = 4;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			case 1:
			{
				int magicPower[] = {1,1,1,1};
				string magicBond[] = {"NNYY","NNYY","YYNN","YYNN"};
				_expected = -1;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			case 2:
			{
				int magicPower[] = {86,15,100,93,53,50};
				string magicBond[] = {"NYYYYN","YNNNNY","YNNYYN","YNYNYN","YNYYNY","NYNNYN"};
				_expected = 332;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			case 3:
			{
				int magicPower[] = {3969,9430,7242,8549,8190,8368,3704,9740,1691};
				string magicBond[] = {"NYYYYYYYY","YNYYYYYYY","YYNYYYYYY","YYYNYYYYY","YYYYNYYYY","YYYYYNYYY","YYYYYYNNY","YYYYYYNNY","YYYYYYYYN"};
				_expected = 57179;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}
			case 4:
			{
				vector<string> magicBonda;
				vector<int> magicPowera(50);
				for (int i = 0; i < 50; i++)
					magicBonda.pb(string(50, 'Y'));
				for (int i = 0; i < 300; i++) {
					int x = rand() % 50;
					int y = rand() % 50;
					magicBonda[x][y] = magicBonda[y][x] = 'N';
				}
				for (int i = 0; i < 50; i++)
					magicPowera[i] = rand() % 100000;
				_expected = -123456;
				_received = _obj.maxMagicPower(magicPowera, magicBonda); 
				break;
			}
			/*case 5:
			{
				int magicPower[] = ;
				string magicBond[] = ;
				_expected = ;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int magicPower[] = ;
				string magicBond[] = ;
				_expected = ;
				_received = _obj.maxMagicPower(vector <int>(magicPower, magicPower+sizeof(magicPower)/sizeof(int)), vector <string>(magicBond, magicBond+sizeof(magicBond)/sizeof(string))); break;
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
