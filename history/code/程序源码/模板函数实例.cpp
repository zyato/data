#include<iostream>
#include<iomanip>
using namespace std;
template<typename T> void sort(T _array[], int len)
{
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if (_array[j] > _array[j + 1]) {
				T temp = _array[j];
				_array[j] = _array[j + 1];
				_array[j + 1] = temp;
			}
		}
	}
}
template<typename T> void show(T _array[], int len) {
	for (int i = 0; i < len; ++i)
	{
		cout.setf(9);
		cout << _array[i] << endl;
	}
		
}
int main()
{
	double a[] = { 3.0,7.57,24.5323,85.45,2.5,5.272,7.0,4.5,43.784,0.3 };
	sort(a, 10);
	show(a, 10);
	system("pause");
	return 0;
}