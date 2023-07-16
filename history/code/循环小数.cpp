#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;


int main() {
	
	int m, n;
	while (scanf("%d %d", &m, &n) == 2){
	


			int mod = 0, shang = 0;
			vector<char> vec;
			int mm = m, nn = n;
			int	flag = 0;
			bool hahahaha = true;
			int xpos = 0;
			int lasts[300][2] = { 0 };
			bool isFind = false;
			int beginx, endx;

			while (true) {

				shang = m / n;
				mod = m % n;
				for (int i = 0; i < flag; ++i) {
					if (lasts[i][0] == shang && lasts[i][1] == mod) {
						isFind = true;
						beginx = i;

					}
				}
				if (isFind)break;
				m = mod * 10;
				lasts[flag++][0] = shang;
				lasts[flag - 1][1] = mod;
				char arr[10] = "0";
				int abcdef = 0;
				while (shang) {
					arr[abcdef++] = shang % 10 + '0';
					shang /= 10;
				}

				int len = strlen(arr);
				for (int i = len - 1; i >= 0; --i) {
					vec.push_back(arr[i]);
				}
				if (hahahaha) {
					xpos = vec.size();
					vec.push_back('.');

					hahahaha = false;
				}
				//
				//m = mod * 10;

			}
			/*for (int i = xpos + 1; i < vec.length(); ++i) {
				string t(vec, i, 3);
			}*/
			printf("%d/%d = ", mm, nn);
			int aaa, bbb;
			if (vec.size() - xpos - 1 > 50) {
				for (int i = 0; i < 50 + xpos + 1; ++i) {
					if (i == beginx + xpos) {
						aaa = i;
						printf("(");
					}
					printf("%c", vec[i]);
				}
				printf("...)\n");
			}
			else {
				for (int i = 0; i < vec.size(); ++i) {
					if (i == beginx + xpos) { printf("("); aaa = i; }
					printf("%c", vec[i]);

				}
				printf(")\n");
			}
			printf("   %d = number of digits in repeating cycle\n\n", vec.size() - aaa);

		
	}

	return 0;
}