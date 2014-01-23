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
class GameOfLifeDivTwo{
public:
	string theSimulation(string b, int T){
		vector<int>a, ap;
		for (int i = 0; i < b.length(); i++)
			a.push_back(b[i] == '1');
		int n = a.size();
#define pr(x) (a[(x+n-1)%n])
#define ne(x) (a[(x+1)%n])
		ap.resize(n);
		for (int i = 1; i <= T; i++) {
			for (int j = 0; j < n; j++)
				ap[j] = (a[j] + pr(j) + ne(j)) > 1;
			a = ap;
		}
		for (int i = 0; i < n; i++)
			b[i] = a[i] + '0';
		return b;
	}
};


