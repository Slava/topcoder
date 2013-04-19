#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define abs(x) (x<0?-(x):x)
#define bit(x,y) ((x>>y)&1)

string Map = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct bigint {
	int a[100];
	bigint() { memset(a, 0, sizeof a); }
	void operator += (bigint b) {
		for (int i = 0; i < 100; i++)
			a[i] += b.a[i];
		for (int i = 0; i < 100; i++)
			if (a[i] > 35) {
				a[i+1] += a[i]/36;
				a[i] %= 36;
			}
	}
	void operator -= (bigint b) {
		for (int i = 0; i < 100; i++)
			a[i] -= b.a[i];
		for (int i = 0; i < 100; i++)
			if (a[i] < 0) {
				a[i] += 36;
				a[i+1]--;
			}
	}
	void operator *= (int b) {
		for (int i = 0; i < 100; i++)
			a[i] *= b;
		for (int i = 0; i < 100; i++)
			if (a[i] > 35) {
				a[i+1] += a[i]/36;
				a[i] %= 36;
			}
	}
	void out() {
		bool was = 0;
		for (int i = 99; i >= 0; i--)
			if (was || a[i]) {
				was = 1;
				printf("%c", Map[a[i]]);
			}
		if (!was)printf("0");
	}
};

bool cmp(bigint a, bigint b) {
	for (int i = 99; i >= 0; i--)
		if (a.a[i] < b.a[i])
			return 1;
		else if (a.a[i] > b.a[i])
			return 0;
	return 0;
}

class HexatridecimalSum {
public:
	string maximizeSum(vector <string> numbers, int k) { 		
		vector<bigint> a, b;
		bigint sum;
		int n = (int)numbers.size();
		for (int i = 0; i < n; i++) {
			bigint cur;
			string number = numbers[i];
			for (int j = 0; j < (int)number.size(); j++)
				cur.a[(int)number.size()-j-1] = number[j] >= '0' && number[j] <= '9' ? number[j] -'0' : number[j] - 'A' + 10;
			a.push_back(cur);
			sum += cur;
		}


		for (int ch = 0; ch < 36; ch++) {
			bigint cur, tmp;
			for (int i = 0; i < n; i++) {
				bool was = 0;
				for (int j = 99; j >= 0; j--) {
					if (a[i].a[j])was = 1;
					if (a[i].a[j] == ch && (ch || was)) {
						tmp.a[j] = 35-ch;
						cur += tmp;
						tmp.a[j] = 0;
					}
				}
			}
		//	printf("if replace all %cs with Zs we receive: ", ch<10?ch+'0':ch+'A'-10); cur.out(); puts("");
			b.push_back(cur);
		}
		sort(b.begin(), b.end(), cmp);
		reverse(b.begin(), b.end());

		bigint ans;
		for (int i = 0; i < k; i++)
			ans += b[i];
		ans += sum;
		bool was = 0;
		string res;
		for (int i = 99; i >= 0; i--)
			if (ans.a[i] || was) {
				was = 1;
				res += Map[ans.a[i]];
			}

		if (res == "")
			res = "0";
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
		cout << "Testing HexatridecimalSum (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1330789199;
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
		HexatridecimalSum _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string numbers[] = {"HELLO"};
				int k = 2;
				_expected = "ZZLLO";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 1:
			{
				string numbers[] = {"500", "POINTS", "FOR", "THIS", "PROBLEM"};
				int k = 5;
				_expected = "1100TC85";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 2:
			{
				string numbers[] = {"TO", "BE", "OR", "NOT", "TO", "BE"};
				int k = 0;
				_expected = "QNO";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 3:
			{
				string numbers[] = {"KEQUALS36"};
				int k = 36;
				_expected = "ZZZZZZZZZ";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			case 4:
			{
				string numbers[] = {"GOOD", "LUCK", "AND", "HAVE", "FUN"};
				int k = 7;
				_expected = "31YUB";
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}
			/*case 5:
			{
				string numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}*/
			/*case 6:
			{
				string numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
			}*/
			/*case 7:
			{
				string numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maximizeSum(vector <string>(numbers, numbers+sizeof(numbers)/sizeof(string)), k); break;
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
