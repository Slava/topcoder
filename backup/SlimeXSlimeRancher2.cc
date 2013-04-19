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

class SlimeXSlimeRancher2{
public:
	int train(vector<int> attributes){
		int mx = 0, ans = 0;
		for (int i = 0; i < attributes.size(); i++) {
			mx = max(mx, attributes[i]);
		}
		for (int i = 0; i < attributes.size(); i++) {
			ans += mx - attributes[i];
		}
		return int(ans);
	}
};


