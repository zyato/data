#include <iostream>
#include <cstring>
using namespace std;

int n = -1, m = -1, t = -1;
bool islive = false;
int index1 = -1, index2 = -1, index3 = -1, index4 = -1;
char arr[7][7] = { '\0' };
bool isSeen[7][7];

void dfs(int i, int j, int cnt) {
	if (i < 0 || i >= n || j < 0 || j >= m) {
		return;
	}
	int temp = t - cnt - (abs(i - index3) + abs(j - index4));
	if (temp < 0 || temp & 1) {//ÆæÅ¼¼ôÖ¦
		return;
	}
	if (i == index3 && j == index4) {
		if (cnt == t) {
			islive = true;
		}
		return;		
	}	

	if (i - 1 >= 0 && !isSeen[i - 1][j] && arr[i-1][j]!='X' && !islive) {
		isSeen[i - 1][j] = true;
		dfs(i - 1, j, cnt + 1);
		isSeen[i - 1][j] = false;
	}
	if (i + 1 < n && !isSeen[i + 1][j] && arr[i + 1][j] != 'X' && !islive) {
		isSeen[i + 1][j] = true;
		dfs(i + 1, j, cnt + 1);
		isSeen[i + 1][j] = false;
	}
	if (j - 1 >= 0 && !isSeen[i][j - 1] && arr[i][j - 1] != 'X' && !islive) {
		isSeen[i][j - 1] = true;
		dfs(i, j - 1, cnt + 1);
		isSeen[i][j - 1] = false;
	}
	if (j + 1 < m && !isSeen[i][j + 1] && arr[i][j + 1] != 'X' && !islive) {
		isSeen[i][j + 1] = true;
		dfs(i, j + 1, cnt + 1);
		isSeen[i][j + 1] = false;
	}
	return;

}
int main() {

	while (cin >> n >> m >> t, n || m || t) {
		islive = false;	
		int wall = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> arr[i][j];
				isSeen[i][j] = false;
				if (arr[i][j] == 'S') {
					index1 = i;
					index2 = j;
					isSeen[i][j] = true;
				}
				else if (arr[i][j] == 'D') {
					index3 = i;
					index4 = j;
				}
				else if (arr[i][j] == 'X') {
					wall++;
				}
			}
		}
		
		if (m*n - wall < t) {
			cout << "NO" << endl;
			continue;
		}
		dfs(index1, index2, 0);
		if (islive) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	

	return 0;
}