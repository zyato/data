#include <iostream>
#include <cstdio>  
#include <cstring> 
#include <queue>
#include <map>
using namespace std;
const int maxn = 9;
int area[10][10], m;
bool visit[10][10];
bool appearH[10][10], appearL[10][10], appearJ[10][10];
int number;
void print() {
	for (int i = 0; i < maxn; ++i) {
		cout << "        ";
		for (int j = 0; j < maxn; ++j) {
			cout << area[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "END!!!" << endl;
}
int getJ(int i, int j) {
	return (i / 3) * 3 + j / 3;
}
bool isFind;
void dfs(int x, int y, int cnt) {	
	

	for (int i = 1; i <= maxn; ++i) {	
		if (isFind)return;
		if (!appearH[x][i] && !appearL[y][i] && !appearJ[getJ(x, y)][i]) {
			area[x][y] = i;
			if (cnt == number) {
				print();
				isFind = true;
				return;
			}
			appearH[x][i] = true;
			appearL[y][i] = true;
			appearJ[getJ(x, y)][i] = true;
			int n = y + 1;
			for (int m = x; m < maxn; ++m) {
				for (; n < maxn; ++n) {
					if (!visit[m][n]) {
						visit[m][n] = true;
						dfs(m, n, cnt + 1);

						visit[m][n] = false;
						goto end;
					}
				}
				n = 0;
			}
		end:;
			appearH[x][i] = false;
			appearL[y][i] = false;
			appearJ[getJ(x, y)][i] = false;
		}	
	}
	return;
}

int main() {
	number = 0;
	isFind = false;
	int x, y;
	memset(visit, false, sizeof(visit));
	memset(appearH, false, sizeof(appearH));
	memset(appearL, false, sizeof(appearL));
	memset(appearJ, false, sizeof(appearJ));
	cout << "INPUT:" << endl;
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxn; ++j) {
			cin >> area[i][j];
			if (area[i][j] == 0) {
				number++;
			}
			else {
				visit[i][j] = true;
				appearH[i][area[i][j]] = true;
				appearL[j][area[i][j]] = true;
				appearJ[getJ(i, j)][area[i][j]] = true;
			}
		}
	}
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxn; ++j) {
			if (area[i][j] == 0) {
				x = i; y = j;
				goto out;
			}
		}
	}
out:;
	cout << endl << "ANSWER:" << endl;
	dfs(x, y, 1);
	return 0;
}
