#include <iostream>
#include <vector>
using namespace std;
vector<int> bigNumberMultiply2(vector<int> vec1, vector<int> vec2)
{	
	vector<int> result(vec1.size() + vec2.size());
	for (int i = 0; i < vec1.size(); ++i)
	{
		for (int j = 0; j < vec2.size(); ++j)
		{
			result[i + j + 1] += vec1[i] * vec2[j];
		}
	}
	for (int k = result.size() - 1; k > 0; --k)
	{
		if (result[k] > 10)
		{
			result[k - 1] += result[k] / 10;
			result[k] %= 10;
		}
	}
	/*
	例如10*10,result的第一位为0,数第一位为0没有意义,所以删掉
	*/
	if (result[0] == 0)
	{
		vector<int>::iterator ite1 = result.begin();
		result.erase(ite1);
	}
	return result;
}

int main() 
{
	
	return 0;
}