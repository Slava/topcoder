// imslavko
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std; 

#define pb push_back
#define bit(x,y) (((x)>>(y))&1)

vector<int> C;
bool u[3001];
class LongestSequence{
public:
	int maxLength(vector <int> C){
		bool inf = 1;
		::C = C;
		for (int i = 0; i < (int)C.size(); i++)
			if (C[0] * C[i] < 0)
				inf = 0;
		if (inf) return -1;

		int l = 1, r = 3000, m;
		while (l <= r) {
			m = (l + r) / 2;
			if (can(m))
				l = m + 1;
			else r = m - 1;
		}
		return l - 1;
	}

	bool can(int len) {
		memset(u, 0, sizeof u);
		queue<int> q;

		q.push(0);

		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int i = 0; i < (int)C.size(); i++)
				if (C[i] + v <= len && C[i] + v >= 0 && !u[C[i] + v]) {
					u[C[i] + v] = 1;
					q.push(C[i] + v);
				}
		}
		
		return !u[0];
	}
};


