#include <iostream>
#include <cstring>
using namespace std;

bool isprime[50] = { 0,
					0,1,1,0,1,0,1,0,0,0,
					1,0,1,0,0,0,1,0,1,0,
					0,0,1,0,0,0,0,0,1,0,
					1,0,0,0,0,0,1,0,0,0,};
int a[25];
int T;
bool isSeen[20];

void dfs(int n) {
	if (n > T)
		return;
	for (int i = 2; i <= T; ++i) {
		if (isSeen[i]==false && isprime[a[n - 1] + i]) {
			isSeen[i] = true;
			a[n] = i;
			if (n == T && isprime[a[T] + 1]) {
				for (int j = 1; j < T; ++j) {
					cout << a[j] << " ";
				}
				cout << a[T] << endl;
			}
			else {
				dfs(n + 1);
			}			
			a[n] = 0;

			isSeen[i] = false;
		}	
	}
}

int main() {
	int kk = 1;
	while (cin >> T) {
		memset(a, 0, sizeof(a));
		memset(isSeen, false, sizeof(isSeen));
		a[1] = 1; 
		cout << "Case " << kk++ << ":" << endl;
		if((T&1)!=1)
			dfs(2);
		cout << endl;
	}

	return 0;
}
