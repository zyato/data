#include <iostream>

using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}



int main() {

	int v[6];
	int k = 1;
	while (cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5], v[0] || v[1] || v[2] || v[3] || v[4] || v[5]) {
		for (int i = 0; i < 5; ++i) {
			if (v[i] > 6) {
				if (v[i] % 2 == 0) {
					v[i] = 6;
				}
				else
					v[i] = 7;
			}
		}
		if (v[5] % 2 == 0)
			v[5] = 0;
		else
			v[6] = 1;
		int sum = v[0] + v[1] * 2 + v[2] * 3 + v[3] * 4 + v[4] * 5 + v[5] * 6;
		bool isDiv = false;
		sum /= 2;
		if (sum % 2 != 0)
			goto aaa;
		for (int a = v[5]; a >= 0; --a) {
			for (int b = v[4]; b >= 0; --b) {
				for (int c = v[3]; c >= 0; --c) {
					for (int d = v[2]; d >= 0; --d) {
						for (int e = v[1]; e >= 0; --e) {
							for (int f = v[0]; f >= 0; --f) {
								int temp1 = a * 6 + b * 5 + c * 4 + d * 3 + e * 2 + f;
								if (temp1 == sum) {
									isDiv = true;
									goto aaa;
								}
								if (temp1 < sum)
									goto aaa;
							}
						}
					}
				}
			}
		}
			
		
		aaa:
		cout << "Collection #" << k++ << ":" << endl;
		if (isDiv) {
			cout << "Can be divided." << endl;
		}
		else
			cout << "Can't be divided." << endl;
	}

	return 0;
}