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

using namespace std; 

#define pb push_back
#define bit(x,y) (((x)>>(y))&1)

int n;
int inf = (1<<30);
vector<string> g;
string knowledge;

int d[16], dd[16];
bool told[16][2];

int go(int mask) {
	memset(d, 0, sizeof d);
	memset(told, 0, sizeof told);

	for (int i = 0; i < n; i++)
		if (knowledge[i] == 'Y')
			d[i] = 3;

	for (int day = 0; day < 33; day++) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += d[i];

		if (cnt == 3 * n)
			return day;
		
		memset(dd, 0, sizeof dd);
		for (int i = 0; i < n; i++)
			for (int rumor = 0; rumor < 2; rumor++)
				if (bit(d[i], rumor^bit(mask, i)) 
					&& !told[i][rumor^bit(mask, i)]) {
					told[i][rumor^bit(mask, i)] = 1;

					for (int j = 0; j < n; j++)
						if (g[i][j] == 'Y')
							dd[j] |= (1<<(rumor^bit(mask, i)));

					break;
				}
		for (int i = 0; i < n; i++)
			d[i] |= dd[i];
	}
	return inf;
}

class Rumor{
public:
	int getMinimum(string knowledge, vector<string> graph){
		n = knowledge.size();
		g = graph;
		::knowledge = knowledge;
		
		int res = inf;
		for (int mask = 0; mask < (1 << n); mask++)
			res = min(res, go(mask));
		if (res == inf)
			res = -1;
		return res;
	}
};


