//GCD（）函数用到了取余（模除）运算，降低了程序的执行效率，可以做些更改：
#include<iostream>
#include<ctime>
int ggcd(int x, int y) {
	while (x % 2 == 0)x /= 2;
	while (y % 2 == 0)y /= 2;
	return x % y == 0 ? y : ggcd(y, x%y);
}
int GCD(int x, int y)
{
	if (x < y)
		return GCD(y, x);
	if (y == 0)
		return  x;
	else
	{
		if (x & 1 == 0)
		{
			if (y & 1 == 0)
				return (GCD(x >> 1, y >> 1) << 1);
			else
				return GCD(x >> 1, y);
		}
		else
		{
			if (y & 1 == 0)
				return GCD(x, y >> 1);
			else
				return GCD(y, x - y);
		}
	}
}
int main() { 
	int a, b;
	while (cin >> a >> b) {
		cout << ggcd(a, b) << endl;
	}

	return 0; 
}
