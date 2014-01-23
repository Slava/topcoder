#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;


class BinaryCode {
public:
	vector<string> decode(string message) {
		vector<int> a;
		for (int i = 0; i < (int)message.size(); i++)
			a.push_back(message[i] - '0');

		vector<string> res;
		for (int first = 0; first < 2; first++) {
			vector<int> b;
			bool bad = false;
			b.push_back(first);
			for (int i = 1; i < (int)a.size(); i++) {
				int got = a[i - 1] - b[i - 1] - (i == 1 ? 0 : b[i - 2]);
				if (got != 0 && got != 1) {
					bad = true; break;
				}

				b.push_back(got);
			}
			if (a.back() != b.back() + (b.size() == 1 ? 0 : b[b.size() - 2]))
				bad = true;
			if (bad)
				res.push_back("NONE");
			else {
				string s;
				for (int i = 0; i < (int)b.size(); i++)
					s.push_back(b[i] + '0');
				res.push_back(s);
			}
		}

		return res;
	}
};

