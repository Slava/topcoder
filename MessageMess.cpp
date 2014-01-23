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

long long d[60] = {1};
string fr[60];
string s, res;
class MessageMess {
	public:
	void rec(int n) {
		if (!n)return;
		rec(n-fr[n].size());
		if (n-fr[n].size())
			res += " ";
		res += fr[n];
	}
	string restore(vector <string> dictionary, string message) {
		s = message;
		int n = (int)s.size();
		for (int i = 0; i < n; i++) {
			if (!d[i])continue;
			foreach(word, dictionary) {
				if (i+word->size() <= n && (*word)==s.substr(i,word->size())) {
					d[i+word->size()] += d[i];
					fr[i+word->size()] = *word;
				}
			}
		}
		
		if (!d[s.size()])
			return "IMPOSSIBLE!";
		if (d[s.size()] > 1)
			return "AMBIGUOUS!";
		rec(s.size());
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
		cout << "Testing MessageMess (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1340182126;
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
		MessageMess _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string dictionary[] = {"HI", "YOU", "SAY"};
				string message = "HIYOUSAYHI";
				_expected = "HI YOU SAY HI";
				_received = _obj.restore(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), message); break;
			}
			case 1:
			{
				string dictionary[] = {"ABC", "BCD", "CD", "ABCB"};
				string message = "ABCBCD";
				_expected = "AMBIGUOUS!";
				_received = _obj.restore(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), message); break;
			}
			case 2:
			{
				string dictionary[] = {"IMPOSS", "SIBLE", "S"};
				string message = "IMPOSSIBLE";
				_expected = "IMPOSSIBLE!";
				_received = _obj.restore(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), message); break;
			}
			case 3:
			{
				string dictionary[] = {"IMPOSS", "SIBLE", "S", "IMPOSSIBLE"};
				string message = "IMPOSSIBLE";
				_expected = "IMPOSSIBLE";
				_received = _obj.restore(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), message); break;
			}
			/*case 4:
			{
				string dictionary[] = ;
				string message = ;
				_expected = ;
				_received = _obj.restore(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), message); break;
			}*/
			/*case 5:
			{
				string dictionary[] = ;
				string message = ;
				_expected = ;
				_received = _obj.restore(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), message); break;
			}*/
			/*case 6:
			{
				string dictionary[] = ;
				string message = ;
				_expected = ;
				_received = _obj.restore(vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string)), message); break;
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
