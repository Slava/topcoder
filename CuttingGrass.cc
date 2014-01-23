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

/* START */

class CuttingGrass{
public:
	int theMin(vector <int> a, vector <int> b, int H){
		int n = (int)a.size();
		vector<int> c, u(a.size());
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - 1; j++)
				if (b[j] > b[j + 1])
					swap(b[j], b[j + 1]),
					swap(a[j], a[j + 1]);
		for (int i = 0; i <= n; i++) {
			int num = -1, mx = -1, sum = 0;
			for (int j = 0; j < n; j++) {
				sum += a[j] + b[j] * i;
				if (a[j] + b[j] * i > mx && !u[j])
					mx = a[j] + b[j] * i, num = j;
			}
			if (sum <= H)
				return i;
			if (num == -1)return -1;
			c.pb(num); u[num] = 1;
			cout << num << endl;
			for (int I = 0; I < c.size(); I++)
				for (int j = 0; j < (int)c.size() - 1; j++)
					if (b[c[j]] > b[c[j + 1]])
						swap(c[j], c[j+1]);
			for (int j = 0; j < c.size(); j++)
				a[c[j]] = -(j + 1) * b[c[j]];
		}
		return -1;
	}
};


