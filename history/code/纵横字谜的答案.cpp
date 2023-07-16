#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <cctype>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
char arr[10][10];
int flag[10][10];
int main() {
	int m, n;
	/*
		0是黑色格或者字母
		1是起始格
		2横向用过
		3纵向用过
		4横向用过的起始格
	*/
	while (scanf("%d %d", &m, &n), m&&n) {
		memset(arr, '\0', sizeof(arr));
		memset(flag, 0, sizeof(flag));
		/*for (int i = 0; i < 10; ++i) {
			flag[i][0] = 1;
			flag[0][i] = 1;
		}*/
		int biaohao = 1;
		bool islast = false;
		bool isout = false;
		bool isfirst = true;
		for (int i = 0; i < m; ++i) {
			//flag[i][0] = 1;
			for (int j = 0; j < n; ++j) {
				scanf(" %c", &arr[i][j]);
				//if(arr[i][j]!=*)
				if (arr[i][j] == '*') {
					//flag[i][j] = 0;
					islast = true;
					/*if (j < n - 1) {
						flag[i][j + 1] = 1;
					}*/
				}
				else {
					if (i == 0 || j == 0)flag[i][j] = biaohao++;
					if (islast == true && i!=0) {
						flag[i][j] = biaohao++;
						islast = false;
					}
					if (i > 0 && arr[i - 1][j] == '*' && flag[i][j]==0)biaohao++;
				}

			}
			islast = false;

		}
	
		
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				
				
				if (flag[i][j] != 0) {
					if (isfirst) {
						isfirst = false;
						printf("%d.", flag[i][j]);
					}
					//isout = true;
					printf("%c", arr[i][j]);
					continue;
				}
			
				if (arr[i][j] == '*') {
					printf("\n");
				//	isout = false;
					isfirst = true;
				}
				else {
					printf("%c", arr[i][j]);
				}
	
			}
			cout << endl;
		//	isout = false;
			isfirst = true;
		}
		puts("*************\n");
		islast = false;
		isout = false;
		isfirst = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {


				if (flag[j][i] != 0) {
					if (isfirst) {
						isfirst = false;
						printf("%d.", flag[j][i]);
					}
					//isout = true;
					printf("%c", arr[j][i]);
					continue;
				}

				if (arr[j][i] == '*') {
					printf("\n");
					//	isout = false;
					isfirst = true;
				}
				else {
					printf("%c", arr[j][i]);
				}

			}
			cout << endl;
			//	isout = false;
			isfirst = true;
		}

	}

	return 0;
}


