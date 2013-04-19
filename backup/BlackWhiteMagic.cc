#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

/* START */

bool u[60];
class BlackWhiteMagic {
public:
	int count ( string s ) {
		int n = s.size(), ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B') {
				for (int j = n - 1; j > i; j--)
					if (s[j] == 'W') {
						if (u[j - i])fprintf(stderr, "%s %d %d\n", "Olmas", i, j);
						ans++;swap(s[i], s[j]);
						u[j - i] = 1;break;
					}
			}
		}
		return ans;
	}
};

