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

int countIn(string s, string t) {
	int r = 0, p = 0;
	while ((p = t.find(s, p)) != string::npos) {
		p++; r++;
	}
	return r;
}

class AkariDaisukiDiv1 {
	public:
	int countF(string A, string B, string C, string S, string F, int k) {
		int res = countIn(F, S), ax, xb, bx, xc, md = (int)1e9 + 7;
		string suff, pref;
		ax = xb = bx = xc = 0;

		for (int i = 0; i < k; i++) {
			if (i < 140) {
				if (S.size() < 140) {
					S = A + S + B + S + C;
					res = countIn(F, S);
					continue;
				} else {
					if (pref == "") {
						pref = S.substr(0, 140);
						suff = S.substr(S.size()-140);
					}

					ax = countIn(F, A+pref.substr(0, F.size()-1));
					xb = countIn(F, suff.substr(suff.size()-F.size()+1)+B+pref.substr(0, F.size()-1));
					xc = countIn(F, suff.substr(suff.size()-F.size()+1)+C);

					pref = (A+pref).substr(0, 140);
					suff = (suff+C).substr(suff.size()+C.size()-140);
				}
			}

			res = (res * 2LL + ax + xb + xc) % md;
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
		cout << "Testing AkariDaisukiDiv1 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1335792257;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AkariDaisukiDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "x";
				string F = "axb";
				int k = 2;
				_expected = 2;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 1:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "x";
				string F = "abcdefghij";
				int k = 1;
				_expected = 0;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 2:
			{
				string Waai = "a";
				string Akari = "a";
				string Daisuki = "a";
				string S = "b";
				string F = "aba";
				int k = 2;
				_expected = 4;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 3:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "d";
				string F = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba";
				int k = 58;
				_expected = 191690599;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 4:
			{
				string Waai = "a";
				string Akari = "x";
				string Daisuki = "y";
				string S = "b";
				string F = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
				int k = 49;
				_expected = 1;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 5:
			{
				string Waai = "waai";
				string Akari = "akari";
				string Daisuki = "daisuki";
				string S = "usushio";
				string F = "id";
				int k = 10000000;
				_expected = 127859200;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 6:
			{
				string Waai = "vfsebgjfyfgerkqlr";
				string Akari = "ezbiwls";
				string Daisuki = "kjerx";
				string S = "jbmjvaawoxycfndukrjfg";
				string F = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs";
				int k = 1575724;
				_expected = 483599313;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 7:
			{
				string Waai = "a";
				string Akari = "a";
				string Daisuki = "a";
				string S = "b";
				string F = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
				int k = 48;
				_expected = 16777215;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			/*case 8:
			{
				string Waai = ;
				string Akari = ;
				string Daisuki = ;
				string S = ;
				string F = ;
				int k = ;
				_expected = ;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}*/
			/*case 9:
			{
				string Waai = ;
				string Akari = ;
				string Daisuki = ;
				string S = ;
				string F = ;
				int k = ;
				_expected = ;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
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
