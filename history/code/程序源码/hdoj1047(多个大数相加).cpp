#include<iostream>
#include<string>
#include<cctype>
using namespace std;


int main() {
	
	int T;
	cin >> T;
	while (T--) {
		string str, sum;
		sum.push_back('0');
		int tt1, tt2, len, jinw, tmp;
		while (cin>>str, str.compare("0") != 0) {
			int i = 0;
			while (str[i++] == '0') {
				str.erase(str.begin());
			}
			reverse(str.begin(), str.end());
			jinw=0;
			tmp = 0;
			tt1 = str.length();
			tt2 = sum.length();
			if (tt2 < tt1) {
				for (int i = 0; i < tt1 - tt2; ++i) {
					sum.push_back('0');
				}
			}
			if (tt2 > tt1) {
				for (int i = 0; i < tt2 - tt1; ++i) {
					str.push_back('0');
				}
			}
			len = str.length();
			for (i = 0; i < len; ++i) {
				tmp = str[i] - '0' + sum[i] - '0' + jinw;
				jinw = tmp / 10;
				sum[i] = '0' + tmp % 10;				
			}
			if (jinw!=0) {
				sum.push_back(jinw + '0');
			}

		}
		reverse(sum.begin(), sum.end());
		cout << sum << endl;

		if (T != 0)
			cout << endl;

		

	}
	

	return 0;
}