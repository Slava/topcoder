
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

class MinimumLiars
{
public:
	int getMinimum(vector<int> claim)
	{
		vector<int>a(110, 0);
		int n = claim.size();
		for (int i = 0; i < (int)claim.size(); i++){
			for (int j = claim[i]; j < 110; j++)
				a[j]++;
		}
		for (int i = 0; i <= claim.size(); i++)
			if (i == n - a[i])
				return i;
		return -1;
	}
};

