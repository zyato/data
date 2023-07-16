#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int primes[N];
bool st[N];

void get_primes()
{
	int cnt = 0;
	//1不是质数也不是合数
	memset(st, 0, sizeof(st));
	for (int i = 2; i <= N; i++) { //////等于N？？？
		if (!st[i]) primes[++cnt] = i;//没有被筛去,说明是质数
		for (int j = 1; i*primes[j] <= N; j++) {
			st[i*primes[j]] = true;//筛去合数
			if (i%primes[j] == 0) break;//核心操作,保证了O(n)的复杂度
		}
	}
}

int main()
{
	//n以内的所有质数
	int n, cnt = 0;
	cin >> n;
	get_primes();
	for (int i = 1; primes[i] <= n; i++) {
		cnt++;
		cout << primes[i] << endl;
	}
	cout << cnt << endl;
	return 0;
}

/**
*    判断某一个数是不是质数（剪枝）
*/

bool is_prime(int x){
        if(x == 1)
            return false;
        if(x == 2||x == 3)
            return true;
        if(x % 6 != 1 && x % 6 != 5)
            return false;
        int s = sqrt(x);
        for(int i = 5; i <= s; i += 6)
            if(x % i == 0 || x % (i + 2) == 0)
                return false;
        return true;
    }