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

int beg[30], a[30], n, inv, found;
int u[30], dp[1<<21];

class StrIIRec {
	public:
	string recovstr(int n, int minInv, string minStr) {
		::n = n;
		inv = minInv;

		for (int i = 0; i < (int)minStr.size(); i++)
			beg[i] = minStr[i]-'a';
		for (int i = 0; i < (1<<n); i++) {
			for (int j = 0; j < n; j++)
				u[j] = (i&(1<<j))?1:0;
			for (int j = n-1; j >= 0; j--) if(!u[j]){
				for (int k = j+1; k < n; k++)
					if (u[k])
						dp[i]++;
				u[j] = 1;
			}
			if(n==2)printf("%d %d\n", i, dp[i]);
		}
//		if (n!=2)return string();
		
		memset(u,0,sizeof u);
		int ch = 0, mask = 0, have = 0;
		for (int i = 0; i < n; i++) {
			int& cur = a[i];
//			printf("i:%d\n",i);
			if (!ch)
				a[i] = beg[i];
//			printf("ch:%d a[i]%d\n", ch, a[i]);
			for (; cur < n; cur++)
				if (!u[cur]) {
//					printf("cur:%d\n", cur);
					int add = 0;
					for (int j = 0; j < i; j++)
						if (a[j] > cur)
							add++;
//					printf("add:%d\n", add);
//					printf("dp+have,inv:%d>=%d\n",add+dp[mask^(1<<cur)]+have,inv);
					if (dp[mask^(1<<cur)]+have+add >= inv) {
						u[cur] = 1;
						mask ^= 1<<cur;
						have += add;
//						printf("OK\n");
						break;
					}
				}
			if (cur != beg[i])
				ch = 1;
		}
		string s="";
		for (int i = 0; i < n; i++)
			s += 'a'+a[i];
		return s;
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
		cout << "Testing StrIIRec (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1339081818;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		StrIIRec _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int minInv = 1;
				string minStr = "ab";
				_expected = "ba";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 1:
			{
				int n = 9;
				int minInv = 1;
				string minStr = "efcdgab";
				_expected = "efcdgabhi";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 2:
			{
				int n = 11;
				int minInv = 55;
				string minStr = "debgikjfc";
				_expected = "kjihgfedcba";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 3:
			{
				int n = 15;
				int minInv = 0;
				string minStr = "e";
				_expected = "eabcdfghijklmno";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 4:
			{
				int n = 9;
				int minInv = 20;
				string minStr = "fcdebiha";
				_expected = "fcdehigba";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			/*case 5:
			{
				int n = ;
				int minInv = ;
				string minStr = ;
				_expected = ;
				_received = _obj.recovstr(n, minInv, minStr); break;
			}*/
			/*case 6:
			{
				int n = ;
				int minInv = ;
				string minStr = ;
				_expected = ;
				_received = _obj.recovstr(n, minInv, minStr); break;
			}*/
			/*case 7:
			{
				int n = ;
				int minInv = ;
				string minStr = ;
				_expected = ;
				_received = _obj.recovstr(n, minInv, minStr); break;
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
