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
class MonochromaticBoard{
public:
	int theMin(vector <string> board){
		int all = 1;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[i].size(); j++)
				if (board[i][j] == 'W')
					all = 0;
		if (all)
			return min(board.size(), board[0].size());
		int res = 0;
		string pat(board[0].size(), 'B');
		for (int i = 0; i < board.size(); i++)
			if (board[i] == pat)
				res++;
		for (int j = 0; j < board[0].size(); j++) {
			int pl = 1;
			for (int i = 0; i < board.size(); i++)
				if (board[i][j] == 'W')
					pl = 0;
			res += pl;
		}
		return res;
	}
};


