
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

vector<vector<double> >a;
class FoxListeningToMusic
{
public:
	vector<double> getProbabilities(vector<int> length, int T)
	{
		int n = (int)length.size();
		vector<double> a(160009, 0), ans(n, 0);
		a[0] = 1;
		for (int p = 0; p < T + 2; p++)
			for (int i = 0; i < n; i++)
				a[p + length[i]] += 1./n * a[p];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < length[i]; j++)
				ans[i] += T - j >= 0 ? a[T - j] * 1./n : 0;
		return ans;
	}
};

