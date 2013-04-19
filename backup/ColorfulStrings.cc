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

typedef long long Int;


class mask {
	public:
		int arr[5];
		mask() { memset(arr, 0, sizeof arr); }
		void set(int k, int x) {
			int i = k / 32, j = k % 32;
			if (x)
				arr[i] |= 1 << j;
			else arr[i] &= ~(1 << j);
		}
		int get(int k) {
			return (arr[k / 32] >> (k % 32)) & 1;
		}
}Mask;

typedef vector<mask> vm;
typedef vector<int> vi;class ColorfulStrings{
public:
	set<Int> Set;
	map<Int, int>M;
	vector<mask> A, B;
	vector<int> Ai, Bi;
	void renew(vm &B, vi &Bi, vm &A, vi &Ai) {
		A.clear(); Ai.clear();
		for (int i = 0; i < (int)B.size(); i++) {
			int c = Bi[i];
			for (int j = 2; j < 10; j++) {
				int k = c, ok = 1; Int r = (Int)j; 
				mask m = B[i];
				if (m.get(M[j]))
					ok = 0;
				m.set(M[j], 1);
				for (; k && ok; k /= 10) {
					r *= (k % 10);
					if (m.get(M[r]))
						ok = 0;
					m.set(M[r], 1);
				}
				if (ok) {
					A.pb(m); Ai.pb(c * 10 + j);
				}
			}
		}
	}
	string getKth(int n, int k) {
		M.clear(); Set.clear();
		if (n > 8 || (n == 1 && k > 10)) return "";
		if (n == 1)
			return string(1, '0' + k - 1);
		for (int i = 0; i < (1 << 8); i++) {
			Int r = 1;
			for (int j = 0; j < 8; j++)
				if (i & (1 << j))
					r *= j + 2;
			Set.insert(r);
		}
		int j = 0;
		for (set<Int>::iterator i = Set.begin(); i != Set.end(); i++)
			M[*i] = j++;
		for (int i = 2; i < 10; i++) {
			Ai.pb(i); 
			Mask.set(M[i], 1);
			A.pb(Mask); Mask.set(M[i], 0);
		}
		for (int i = 2; i <= n; i++)
			if (i & 1)
				renew(B, Bi, A, Ai);
			else renew(A, Ai, B, Bi);
		if (!(n & 1))
			A = B, Ai = Bi;
		if (k > (int)A.size()) {
			cout << "two much numbers, I have only " << A.size() << endl;
			return "";
		}
		string s = "";
		for (int c = Ai[k - 1]; c; c /= 10)
			s.pb(c % 10 + '0');
		reverse(s.begin(), s.end());
		return s;
	}
};


