#include<iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int previo[9] = { 0,0,0,0,1,0,2,3,5 };
	int w[9] = { 0,5,1,8,4,6,3,2,4 };
	int dp[10] = { 0 };
	dp[0] = 0;
	for (int i = 1; i < 9; ++i)
		dp[i] = max(w[i] + dp[previo[i]], dp[i - 1]);
	for (int i = 0; i < 9; ++i) 
		cout << dp[i] << endl;
	return 0;
}




/*#include<iostream>
#include<cmath>

using namespace std;

int previo[9] = { 0,0,0,0,1,0,2,3,5 };
int w[9] = { 0,5,1,8,4,6,3,2,4 };
int dp[10] = {0};
int max(int a, int b)
{
	return a > b ? a : b;
}
int OPT(int i)
{
	if (i == 0) return 0;
	return max(OPT(i - 1), w[i] + OPT(previo[i]));
}
int opt(int i)
{
	if (i == 0) return 0;
	if (dp[i] != 0) return dp[i];
	return dp[i] = max(opt(i - 1), w[i] + opt(previo[i]));
}
int main()
{
	
	opt(8);
	for (int i = 0; i < 10; ++i)
		cout << dp[i] << endl;
	return 0;
}*/