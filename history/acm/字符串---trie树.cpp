#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;
struct node {
	int nxt[maxn][26], cnt[maxn], root, cur;
	int newnode(){
		for (int i = 0; i < 26; i++)nxt[cur][i] = -1;
		cnt[cur++] = 0;
		return cur - 1;
	}
	void init() {
		cur = 0;
		root = newnode();
	}
	void insert(string s) {
		int len = s.length();
		int now = root, idx;
		for (int i = 0; i < len; i++) {
			idx = s[i] - 'a';
			if (nxt[now][idx] == -1) {
				nxt[now][idx] = newnode();
			}			
			now = nxt[now][idx];
			cnt[now]++;
		}
	}
	int query(string s) {
		int len = s.length();
		int now = root, idx;
		for (int i = 0; i < len; i++) {
			idx = s[i] - 'a';
			if (nxt[now][idx] == -1) return 0;
			now = nxt[now][idx];
		}
		return cnt[now];
	}
};
node trie;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	freopen("in.txt", "r", stdin);
	trie.init();
	string s;
	while (getline(cin, s) && islower(s[0])) {
		trie.insert(s);
	}
	while (cin >> s)
		cout << trie.query(s) << endl;
	return 0;
}