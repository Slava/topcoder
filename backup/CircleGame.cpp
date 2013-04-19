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

int val[256], n;
bool used[100];
vector<int> a;
class CircleGame {
	public:
	int cardsLeft(string deck) {
		for (int i = 2; i < 10; i++)
			val[i+'0'] = i;
		val['A'] = 1; val['T'] = 10; val['J'] = 11; val['Q'] = 12; val['K'] = 13;
		for (int i = 0; i < (int)deck.size(); i++)
			a.pb(val[deck[i]]);
		int was = (int)a.size();
		for (int CNT = 0; CNT < 50*50+100; CNT++) {
			for (int i = 0; i+1 < (int)a.size(); i++)
				if (a[i]+a[i+1]==13) {
					a.erase(a.begin()+i, a.begin()+i+2);
					break;
				}
			for (int i = 0; i < (int)a.size(); i++)
				if (a[i] == 13)
					a.erase(a.begin()+i);
			if (a[0] + a.back() == 13) {
				a.erase(a.end()-1);
				a.erase(a.begin());
			}
			if (was == a.size())break;
			was = (int)a.size();
		}
		return a.size();
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
		cout << "Testing CircleGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1339772685;
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
		CircleGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string deck = "KKKKKKKKKK";
				_expected = 0;
				_received = _obj.cardsLeft(deck); break;
			}
			case 1:
			{
				string deck = "KKKKKAQT23";
				_expected = 1;
				_received = _obj.cardsLeft(deck); break;
			}
			case 2:
			{
				string deck = "KKKKATQ23J";
				_expected = 6;
				_received = _obj.cardsLeft(deck); break;
			}
			case 3:
			{
				string deck = "AT68482AK6875QJ5K9573Q";
				_expected = 4;
				_received = _obj.cardsLeft(deck); break;
			}
			case 4:
			{
				string deck = "AQK262362TKKAQ6262437892KTTJA332";
				_expected = 24;
				_received = _obj.cardsLeft(deck); break;
			}
			/*case 5:
			{
				string deck = ;
				_expected = ;
				_received = _obj.cardsLeft(deck); break;
			}*/
			/*case 6:
			{
				string deck = ;
				_expected = ;
				_received = _obj.cardsLeft(deck); break;
			}*/
			/*case 7:
			{
				string deck = ;
				_expected = ;
				_received = _obj.cardsLeft(deck); break;
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
