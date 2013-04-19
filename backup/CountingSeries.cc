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
class CountingSeries{
public:
	long long countThem(long long a, long long b, long long c, long long d, long long upperBound){
		long long num = (upperBound - a) / b + 1;
		if (upperBound < a)
			num = 0;
		long long res = num, A = c, pr = c;
		cout << res << endl;
		for (int i = 0; i < 60; i++) {
			if (A > upperBound || A < pr) {
				cout << A << " << stop" << endl;
				break;
			}
			cout << "is " << A << endl;
			long long tmp = A - a;
			if (tmp < 0 ||  tmp % b != 0) {
				res++;
			}
			else cout << "not" << endl;
			pr = A;
			A *= d;
			if (pr == A)
				break;
		}	
		return res;
	}
};


