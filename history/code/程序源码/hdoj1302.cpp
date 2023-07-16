#include <iostream>

using namespace std;

int min(int a, int b, int c, int d) {
	int t1 = a < b ? a : b;
	int t2 = c < d ? c : d;
	return t1 < t2 ? t1 : t2;
}

int main()
{
	int n;
	int arr[5845] = { 0, 1, 2, 3 ,4 ,5 ,6,7,8,9,10,12 };
	int t2=1, t3=1, t5=1, t7=1;
	for (int i = 12; i <= 5842; ++i) {
		while (arr[t2] * 2 <= arr[i-1]) {
			t2++;
		}
		while (arr[t3] * 3 <= arr[i-1]) {
			t3++;
		}
		while (arr[t5] * 5 <= arr[i-1]) {
			t5++;
		}
		while (arr[t7] * 7 <= arr[i-1]) {
			t7++;
		}
		arr[i] = min(arr[t2] * 2, arr[t3] * 3, arr[t5] * 5, arr[t7] * 7);
	}
	//char str[5][3] = { {'t','h', '\0'} ,{'s','t', '\0'} ,{'n','d', '\0'} ,{'r','d', '\0'} ,{'t','h', '\0'} };
	while (cin >> n, n) {
		

			//printf("The %d%s humble number is %d.\n", n, str[f], arr[n]);
		/*cout << "The " << n;
		if (n % 10 == 1 && n != 11)
			cout << "st";
		else if (n % 10 == 2 && n != 12)
			cout << "nd";
		else if (n % 10 == 3 && n != 13)
			cout << "rd";
		else
			cout << "th";
		cout << " humble number is " << arr[n] << "." << endl;*/
		printf("The %d", n);
		if (n % 10 == 1 && n % 100 != 11)
			printf("st");
		else if (n % 10 == 2 && n % 100 != 12)
			printf("nd");
		else if (n % 10 == 3 && n % 100 != 13)
			printf("rd");
		else
			printf("th");
		printf(" humble number is %d.\n", arr[n]);
	
		//我的天呢， 111是th， 果真是英语不好；
	}
	
	return 0;
}