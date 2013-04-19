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

class Bonuses{
public:
	vector<int> getDivision(vector<int> points){
		vector<int> a(points.size()), u(points.size());
		int sum = 0, left = 100;
		for (int i = 0; i < (int)points.size(); i++)
			sum += points[i];
		for (int i = 0; i < (int)a.size(); i++) {
			a[i] = (points[i] + .0) / sum * 100;
			left -= a[i];
		}
		
		for (int i = 0; i < left; i++) {
			int mx = -1;
			for (int j = 0; j < (int)a.size(); j++)
				if (!u[j] && (mx == -1 || points[j] > points[mx]))
					mx = j;
			a[mx]++;
			u[mx] = 1;
		}
		return a;
	}
};


