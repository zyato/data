#include<iostream>

using namespace std;
//递归实现
int gongshi(int a, int b, int n) {
	if (n == 1 || n == 2)
		return 1;
	return (a * gongshi(a, b, n - 1) + b * gongshi(a, b, n - 2)) % 7;

}
int main() {
	int a, b, n;
	while (cin >> a >> b >> n, a || b || n) {
		int val = 0;
		int last2 = 1;
		int last1 = 1;
		n %= 49;
		for (int i = 1; i <= n; ++i) {
			if (i == 1 || i == 2) {
				val = 1;

			}
			else {
				val = (a * last1 + b * last2) % 7;
				last2 = last1;
				last1 = val;
			}
		}
		cout << val << endl;
	}


	return 0;
}
/*
*    1. n%=49    f(n)范围为[0. 6], 共49种组合, 以后会循环.
*
*/