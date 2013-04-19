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

class BinaryCode {
	public:
	string decode(string s, int last) {
		string res;
		res += last + '0';

		for (int i = 1; i < (int)s.size(); i++) {
			int cur = s[i-1]-'0';
			cur -= last;
			res += cur + '0';
			s[i] -= last;
			last = cur;

			if (last != 0 && last != 1)
				return "NONE";
			if (s[i] != '0' && s[i] != '1' && s[i] != '2')
				return "NONE";
		}

		if (last+'0' != s[s.size()-1])
			return "NONE";
		return res;
	}

	vector <string> decode(string message) {
		vector<string> res;
		res.pb(decode(message, 0));
		res.pb(decode(message, 1));
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
		cout << "Testing BinaryCode (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1338191802;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BinaryCode _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string message = "123210122";
				string __expected[] = { "011100011",  "NONE" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decode(message); break;
			}
			case 1:
			{
				string message = "11";
				string __expected[] = { "01",  "10" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decode(message); break;
			}
			case 2:
			{
				string message = "22111";
				string __expected[] = { "NONE",  "11001" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decode(message); break;
			}
			case 3:
			{
				string message = "123210120";
				string __expected[] = { "NONE",  "NONE" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decode(message); break;
			}
			case 4:
			{
				string message = "3";
				string __expected[] = { "NONE",  "NONE" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decode(message); break;
			}
			case 5:
			{
				string message = "12221112222221112221111111112221111";
				string __expected[] = { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decode(message); break;
			}
			/*case 6:
			{
				string message = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decode(message); break;
			}*/
			/*case 7:
			{
				string message = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decode(message); break;
			}*/
			/*case 8:
			{
				string message = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.decode(message); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
