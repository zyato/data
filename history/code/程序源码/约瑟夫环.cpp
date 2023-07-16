/*
时	  间：2019年4月3日，22点26分
功能：
目的：
问题描述：N个人围成一圈，从第一个人开始报数，报到m的人出圈，剩下的人继续从1开始报数，报到m的人出圈；
		如此往复，直到所有人出圈。（模拟此过程，输出出圈的人的序号）

*/
#include<iostream>
using namespace std;
int a(int n, int m) {
	if (n == 1)
		return 0;
	else
		return (a(n - 1, m) + m) % n;
}
int main() {
	int n;
	cin >> n;
	const int m = 3;
	cout << a(n, 3) + 1 << endl;;
	int s = 0;
	for (int i = 2; i <= n; ++i)
		s = (s + m) % i;
	cout << s + 1;

	return 0;
}
/*
在vs2017的输出结果是：

收获：提升算法能力！
*/