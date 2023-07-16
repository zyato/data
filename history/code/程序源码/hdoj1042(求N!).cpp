#include <iostream>
#include <vector>

using namespace std;



int main() {
	int n;
	while (cin >> n) {
		if (1 == n || 0 == n) {
			cout << "1" << endl;
			continue;
		}
		vector<int> vec;
		vec.push_back(1);
		int jinw = 0;
		for (int i = 2; i <= n; ++i) {
			for (auto j = vec.begin(); j != vec.end(); ++j) {
				*j = i * (*j) + jinw;
				jinw = *j / 10;
				*j %= 10;
			}
			while (jinw != 0) {
				vec.push_back(jinw % 10);
				jinw /= 10;
			}
		}
		reverse(vec.begin(), vec.end());
		for (auto i = vec.begin(); i != vec.end(); ++i) {
			cout << *i;
		}
		cout << endl;
		

	}

	return 0;
}
