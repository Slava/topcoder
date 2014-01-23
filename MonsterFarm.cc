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
#include <sstream>
#include <queue>

using namespace std; 

#define pb push_back
#define bit(x,y) (((x)>>(y))&1)

const int N = 60;
int a[N][N], b[N][N], c[N][N], u[N];
int mod = 1000000007;

void mult(int a[N][N], int b[N][N]) {
	memset(c,0,sizeof c);
	for (int i = 0; i < 60; i++)
		for (int j= 0 ; j < 60; j++)
			for (int k = 0; k < 60; k++)
				c[i][j] = (c[i][j] + (a[i][k] * 1LL * b[k][j]) % mod) % mod;
	for (int i = 0; i < 60; i++)
		for (int j = 0; j < 60; j++)
			a[i][j] = c[i][j];
}

int go(int n) {
	int res = 0;
	for (int i = 0; i < n; i++)
		mult(a,a);
	for (int i = 0; i < 60; i++)
		res = (res + a[0][i]) % 1000000007;
	return res;
}

class MonsterFarm{
public:
	int numMonsters(vector <string> transforms){
		memset(a,0,sizeof a);
		for (int i = 0; i < (int)transforms.size(); i++) {
			stringstream in;
			in << transforms[i];
			int x;
			while (in >> x) {
				a[i][x-1]++;
			}
		}
		
		queue<int> q;
		q.push(0);
		memset(u, 0, sizeof u);

		while (!q.empty()) {
			int v = q.front(); q.pop();
			u[v] = 1;
			for (int i = 0; i < 60; i++)
				if (a[v][i] > 1) {
					if (u[i])
						return -1;
					u[i] = 1;
					q.push(i);
				}
		}

		return go(30)==go(20)?go(0):-1;
	}
};


