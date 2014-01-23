
// {{{ Boilerplate Code <--------------------------------------------------
//
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}

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

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;

// }}}

class SquareFreeNumbers
{
public:
	bool check (long long a){
		for (long long i = 2; i <= a; i++){
			if (i * i > a) i = a;
			if (a % i == 0)
				a /= i;
			if (a % i == 0)
				return true;
		}
		return false;
	}
	int getCount(long long min, long long max)
	{
		int ans = 0;
		for (; min <= max; min++){
			ans += check(min);
		}
		return ans;
	}
};

