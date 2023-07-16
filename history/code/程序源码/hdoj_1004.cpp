#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	while (cin >> n, n)
	{
		int max = 0;
		int flag = 0;
		vector<string> vec;
		for (int i = 0; i < n; ++i) {
			string t;
			cin >> t;
			vec.push_back(t);
		}
		for (int i = 0; i < n; ++i) {
			int cnt = count(vec.begin(), vec.end(), vec[i]);
			if (cnt > max) {
				max = cnt;
				flag = i;
			}
		}
		cout << vec[flag] << endl;
	}

	return 0;
}