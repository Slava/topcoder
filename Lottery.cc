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

class item {
public:
	string name;
	int all, pick;
	long long possible;
	bool sorted, unique;

	item(string rule) {
		int i = 0;
		for (; i < (int)rule.size(); i++)
			if (rule[i] == ':') {
				i += 2;
				break;
			}
			else name.push_back(rule[i]);
		
		all = 0;
		for (; i < (int)rule.size(); i++)
			if (rule[i] == ' ') {
				i++;
				break;
			}
			else all = all * 10 + rule[i] - '0';

		pick = 0;
		for (; i < (int)rule.size(); i++)
			if (rule[i] == ' ') {
				i++;
				break;
			}
			else pick = pick * 10 + rule[i] - '0';

		sorted = (rule[rule.size() - 3] == 'T');
		unique = (rule[rule.size() - 1] == 'T');
		
		possible = 1;
		if (!unique && !sorted) {
			for (int i = 0; i < pick; i++)
				possible *= all;
		} else if (!unique && sorted) {
			for (int i = all; i < pick + all; i++)
				possible *= i;
			for (int i = 1; i <= pick; i++)
				possible /= i;
		} else if (unique && !sorted) {
			for (int i = all - pick + 1; i <= all; i++)
				possible *= i;
		} else {
			for (int i = all - pick + 1; i <= all; i++)
				possible *= i;
			for (int i = 1; i <= pick; i++)
				possible /= i;
		}
	}

};
bool operator < (item l, item p) {
	if (l.possible == p.possible)
		return l.name < p.name;
	return l.possible < p.possible;
}

class Lottery{
public:
	vector<string> sortByOdds(vector<string> rules){
		vector<item> a;
		for (int i = 0; i < (int)rules.size(); i++)
			a.push_back(item(rules[i]));
		sort(a.begin(), a.end());
		vector<string> res;
		for (int i = 0; i < (int)a.size(); i++)
			res.push_back(a[i].name);
		return res;
	}
};


