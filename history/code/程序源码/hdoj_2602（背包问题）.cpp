#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

//int max(int a, int b) {
//    return a > b ? a : b;
//}
#define max(a, b) (a>b?a:b)
int main() {
	int T;
	cin >> T;
	while (T--) {
		int myn, myv;
		cin >> myn >> myv;
		int * val = new int[myn + 1];
		val[0] = 0;
		for (int i = 1; i <= myn; ++i) {
			cin >> val[i];
		}
		int * v = new int[myn + 1];
		v[0] = 0;
		
		for (int i = 1; i <= myn; ++i) {
			cin >> v[i];

		}
		int dp[100][100] = { 0 };
		

		for (int i = 1; i <= myn; ++i) {
			for (int j = 0; j <= myv; ++j) {

				if (j < v[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + val[i]);
				}
			}
		}
		for (int i = 0; i <= myn; ++i) {
			for (int j = 0; j <= myv; ++j) {
				cout << dp[i][j] << "  ";
			}
			cout << endl;
		}
		cout << dp[myn][myv] << endl;
		//delete[] val;
		//delete[] v;
	}


	return 0;
}
//int dp(int (*v)[2], int roy, int len) {
//	if (roy <= 0||len<=0) {
//		return 0;
//	}
//	int m = 0;
//	if (roy >= v[len - 1][1]) {
//		m = v[len - 1][0] + dp(v, roy - v[len - 1][1], len - 1);
//	}
//	int n = dp(v, roy, len - 1);
//	return m > n ? m : n;
//
//}
//
//
//int main() {
//	
//	int t;
//	cin >> t;
//	while (t--) {
//		
//
//	}
//
//
//	return 0;
//}