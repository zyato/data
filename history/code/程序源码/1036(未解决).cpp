#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include<cmath>
using namespace std;



int main() {
	int n;
	float d;
	cin >> n >> d;
	getchar();
	string aa;
	
	while (getline(cin, aa)) {
		bool isHaveScore = true;
		int tmp = 0, tmp2 = 2;;
		for (int i = 0; i < 3; ++i) {
			if (aa[i] != ' ') {
				tmp += (aa[i] - '0') * pow(10, tmp2);
			}
			tmp2--;
		}
		cout << setw(3) << tmp << ": ";
		int hour = 0, minute = 0, second = 0;
		for (int i = 0; i < n; ++i) {
			if (aa[4 + i * 8] == '-') {
				isHaveScore = false;
				break;
			}
			hour += aa[4 + i * 8] - '0';
			minute += (aa[6 + i * 8] - '0') * 10 + aa[7 + i * 8] - '0';
			second += (aa[9 + i * 8] - '0') * 10 + aa[10 + i * 8] - '0';

		}
		if (isHaveScore) {
			second += hour * 3600 + minute * 60;
			tmp = second *1.0/ d+0.5;
			int tmp1 = tmp / 60;
			tmp2 = tmp - tmp1 * 60;
			cout << tmp1 << ":";
			if (tmp2 >= 10) {
				cout << tmp2;
			}
			else if (tmp2 == 0) {
				cout << "00";
			}
			else {
				cout << " " << tmp2;
			}
			cout<<" min/km" << endl;
		}
		else {
			cout << "-" << endl;
		}
		
	}
	
	
	
	return 0;
}