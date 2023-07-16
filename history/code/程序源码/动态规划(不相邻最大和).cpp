#include<iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int a[7] = { 1,2,4,1,7,8,3 };
	int tar[7] = { 0 };
	tar[0] = a[0];
	tar[1] = max(a[0], a[1]);
	for (int i = 2; i < 7; ++i) {
		tar[i] = max(a[i] + tar[i - 2], tar[i - 1]);
	}
	for (int i = 0; i < 7; ++i)
		cout << tar[i] << endl;


	return 0;
}


/*#include<iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
int haha(int arr[], int n) {
	if (n == 0)
		return arr[0];
	if (n == 1)
		return max(arr[0], arr[1]);
	int a = haha(arr, n - 2) + arr[n];
	int b = haha(arr, n - 1);
	return max(a, b);
}
int main() {
	int a[7] = { 1,2,4,1,7,8,3 };
	cout<<haha(a, 6);


	return 0;
}*/