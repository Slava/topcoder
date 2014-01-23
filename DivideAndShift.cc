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
#include <bitset>

using namespace std;

#define pb push_back
#define bit(x,y) (((x)>>(y))&1)


/* START */


bool prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}
class DivideAndShift {
public:
	int getLeast(int N, int M) {
		queue<int>q; bitset<100000001>u;
		q.push(N); u[N] = 1;
		map<int, int> Map;
		int ans = (1 << 30); M--;
		while(!q.empty()) {
			int v = q.front(), m = M % v; q.pop();
			int foran = Map[v];
			ans = min(ans, foran + m);
			ans = min(ans, foran + v - m);
			for (int i = 2; i * i <= v; i++ )
				if (v % i == 0) {
					if (prime(i) && u[v/i] == 0) {
						u[v/i] = 1; Map[v/i] = foran + 1;
						q.push(v/i);
					}
				}
			if (prime(v) && u[1] == 0) {
				u[1] = 1; Map[1] = foran + 1; q.push(1);
			}
		}
		return ans;
	}
};

