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

bool u[51][1000020];
class KindAndCruel {
public:
	int crossTheField (string s, int K, int C) {
		int n = s.size(), m = 1000000;
		for (int i = 0; i < m; i++)
			u[0][i] = 1;
		for (int i = 1; i < n; i++){
			for (int j = 0; j < m; j++){
				if (s[i] == '.'){
					if (u[i - 1][j])
						u[i][j + 1] = 1;
					if (u[i][j])
						u[i][j + 1] = 1;
				}
				if (s[i] == 'K'){
					if (u[i - 1][j] && ((j + 1) % K != 0))
						u[i][j + 1] = 1;
					if (u[i][j] && (j + 1) % K != 0)
						u[i][j + 1] = 1;
				}
				if (s[i] == 'C'){
					if (u[i - 1][j] && ((j + 1) % C == 0))
						u[i][j + 1] = 1;
					if (u[i][j] && ((j + 1) % C == 0))
						u[i][j + 1] = 1;
				}
			}
		}
		for (int i = 0; i < m; i++)
			if (u[n - 1][i])
				return i;
		return -1;
	}
};

