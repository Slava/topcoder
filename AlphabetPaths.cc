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

class AlphabetPaths{
public:
	int n, m;
	vector<long long> cnt;
	vector<string> letterMaze;
	vector<int> allSets;
	vector<vector<int> >Maze;
	map<char,int>Map;
	long long count(vector <string> letterMaze){
		n = (int)letterMaze.size();
		m = (int)letterMaze[0].size();
		this->letterMaze = letterMaze;
		long long res = 0;
		Maze.assign(n, vector<int>(m, -1));

		int lettersNumber = 0;
		for (int i = 'A'; i <= 'Z'; i++)
			if (i != 'G' && i != 'J' && i != 'U' && i != 'W' && i != 'Y')
				Map[i] = lettersNumber++;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				Maze[i][j] = Map[letterMaze[i][j]];

		cnt.assign(1<<21, 0LL);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (letterMaze[i][j] != '.') {
					allSets.clear();
					go(i,j,0,0);
					for (int k = 0; k < (int)allSets.size(); k++) {
						int set = allSets[k];
						int oppset = set ^ ((1<<21)-1) ^ (1<<Maze[i][j]);
						res += cnt[set] * cnt[oppset];
					}

					for (int k = 0; k < (int)allSets.size(); k++)
						cnt[allSets[k]] = 0;
				}

		return res;
	}

	void go(int x, int y, int N, int mask) {
		if (x < 0 || x >= n || y < 0 || y >= m ||
		letterMaze[x][y] == '.' || bit(mask, Maze[x][y]))
			return;
		mask |= (1 << Maze[x][y]);
		N++;
		if (N == 11) {
			if (!cnt[mask])
				allSets.push_back(mask);
			cnt[mask]++;
			return;
		}

		go(x + 1, y, N, mask);
		go(x - 1, y, N, mask);
		go(x, y + 1, N, mask);
		go(x, y - 1, N, mask);
	}
};


