
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int visit[155][155], vis[150], h, l, graph[155][155], dist[150][150], dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
void bfs(int i, int j, int n) {
	memset(visit, -1, sizeof(visit));
	queue<pair<int, int> > Q;
	Q.push(make_pair(i, j));
	visit[i][j] = 0;
	int a, b, x, y;
	while (!Q.empty()) {
		a = Q.front().first; b = Q.front().second; Q.pop();
		if (graph[a][b] > graph[i][j]) {
			dist[graph[a][b]][graph[i][j]] = visit[a][b];
			dist[graph[i][j]][graph[a][b]] = visit[a][b];
			n--;
			if (!n)return;
		}
		for (int ii = 0; ii < 4; ++ii) {
			x = a + dir[ii][0]; y = b + dir[ii][1];
			if (x < 0 || y < 0 || x >= h || y >= l)continue;
			if (graph[x][y] != -1 && visit[x][y] == -1) {
				Q.push(make_pair(x, y));
				visit[x][y] = visit[a][b] + 1;
			}
		}
	}
}
int prim(int val, int cnt) {
	int minVal;
	int total = 0;
	memset(vis, 0, sizeof(vis));
	vector<int> vec;
	vec.push_back(val);
	vis[val] = 1;
	while (true) {
		int x = 0;
		minVal = 0x3f3f3f3f;
		for (int i = 0, len = vec.size(); i < len; ++i) {
			for (int j = 1; j < cnt; ++j) {
				if (!vis[j] && dist[vec[i]][j] < minVal) { minVal = dist[vec[i]][j]; x = j; }
			}
		}
		if (minVal == 0x3f3f3f3f)return total;
		total += minVal;
		vec.push_back(x);
		vis[x] = 1;
	}
}
/*
1
6 5
#####
#A#A##
# # A#
#S  ##
#####
*/
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> l >> h;
		while (getchar() != '\n');
		string str;
		int cnt = 1, len;
		memset(dist, 0x3f, sizeof(dist));
		memset(graph, -1, sizeof(graph));
		for (int i = 0; i < h; ++i) {
			getline(cin, str);
			len = str.length();
			for (int j = 0; j < len; ++j) {
				//-1表示墙， 0表示空格， 1-n表示外星人；
				if (str[j] == '#')graph[i][j] = -1;
				else if (str[j] == 'A')graph[i][j] = cnt++;
				else if (str[j] == 'S')graph[i][j] = cnt++;
				else graph[i][j] = 0;
			}
		}

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < l; ++j) {
				if (graph[i][j] > 0) {
					bfs(i, j, cnt - graph[i][j] - 1);
				}
			}
		}
		cout << prim(1, cnt) << endl;
	}
	return 0;
}