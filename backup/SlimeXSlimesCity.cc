// imslavko
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define bit(x,y) (((x)>>(y))&1)

class SlimeXSlimesCity{
public:
	int merge(vector<int> population){
		sort (population.begin(), population.end());
		long long r;
		int res = 0, ok;
		for (int i = 0; i < population.size(); i++) {
			r = 0;ok = 1;
			for (int j = 0; j < i + 1; j++) {
				r += population[j];
			}
			for (int j = i + 1; j < population.size(); j++) {
				if (population[j] > r){ok = 0; break;}
				r += population[j];
			}
			res += ok;
		}
		return int(res);
	}
};


