#include <bits/stdc++.h>
using namespace std;
/*
ac自动机解决的问题：给定n个模式串和1个文本串，求有多少个模式串在文本串里出现过。
fail指针的确定：当前节点的fail指针指向他父亲节点的fail指针指向的那个节点的具有相同字母的子节点。fail[cur] = nxt[fail[fa(cur)]][val(cur)]
附加：一个节点的fail指针指向的结点所代表的字符串是该节点所代表字符串的后缀。
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 * 10000 + 5;

struct node {
	int nxt[maxn][26], end[maxn], fail[maxn];
	int root, cur;
	int newnode() {
		for (int i = 0; i < 26; ++i)nxt[cur][i] = -1;
		end[cur++] = 0;
		return cur - 1;//不能用end[cur]=0;return cur++;因为return cur++的返回的值会出问题。
	}
	void init() {
		cur = 0;
		root = newnode();
	}
	void insert(string& s) {
		int len = s.length();
		int now = root, idx;
		for (int i = 0; i < len; ++i) {
			idx = s[i] - 'a';
			if (nxt[now][idx] == -1) {
				nxt[now][idx] = newnode();
			}
			now = nxt[now][idx];
		}
		end[now]++;//一个串的结尾，做个记录。
	}
	void getFail() {
		// 某一节点的fail指针指向，此节点的父节点（now）的fail指针所指向的节点的与此节点值相同的儿子节点
		queue<int> Q;
		fail[root] = root;
		for (int i = 0; i < 26; ++i) {//预处理根节点的儿子的fail指针。
			//如果根节点该儿子不存在，后面如果找到了此节点，就需要从根节点继续找，
			//所以把此节点值改为root，后续，就不会出现匹配不到的情况，压缩查找路径。
			if (nxt[root][i] == -1)nxt[root][i] = root; 
			else {
				fail[nxt[root][i]] = root; // 根节点所有存在的儿子，匹配失败，肯定要从root重新匹配。
				Q.push(nxt[root][i]); // 节点存在，当然需要处理当前节点的儿子。
			}
		}
		while (!Q.empty()) { // 处理所有有儿子的节点的fail指针。
			int now = Q.front(); Q.pop();
			for (int i = 0; i < 26; ++i) {
				/*
					因为，后续查找fail指针时，如果找到了此节点，而此节点恰好不存在，就需要继续寻找此节点
					的fail指针，为了节省后续操作，直接计算出此节点的fail指针，让此节点的值等于此节点的fail指针
					（后续操作就不用再考虑fail指针不存在的情况，也就是压缩查找路径）。
				*/
				if (nxt[now][i] == -1)nxt[now][i] = nxt[fail[now]][i]; 
				else {
					fail[nxt[now][i]] = nxt[fail[now]][i];
					Q.push(nxt[now][i]);
				}
			}
		}
	}
	int query(string& s) {
		int len = s.length();
		int now = root, t, ans = 0;
		for (int i = 0; i < len; ++i) {
			now = nxt[now][s[i] - 'a'];
			t = now;
			/*
			如果一个字符串匹配成功，那么他的Fail也可以匹配成功（后缀嘛[此节点的fail指针所代表的字符串是该节点路径
			字符串的后缀]），于是我们就把Fail再统计答案，同样，Fail的Fail也可以匹配成功，以此类推……
			*/
			while (t != root) {
				ans += end[t];
				end[t] = 0; // 防止后续重复计算。这就意味着，只能求出1个文本串中，模式串出现次数。
				t = fail[t];
			}
		}
		return ans;
	}
	/*void debug()
	{
		for (int i = 0; i < cur; i++)
		{
			printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
			for (int j = 0; j < 26; j++)
				printf("%2d", nxt[i][j]);
			printf("]\n");
		}
	}*/
};
node ac;
int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int T; cin >> T;
	string s;
	while (T--) {
		int n; cin >> n;
		ac.init();
		for (int i = 0; i < n; ++i) {
			cin >> s;
			ac.insert(s);
		}
		ac.getFail();
		cin >> s;
		cout << ac.query(s) << endl;
	}

	return 0;
}