#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	int array[] = {3,5,6,3,4,7,8,1,4,7,0,23,12,-1,11};
	int sum = 11;
	unordered_set<int> hash_set;

	for(int i = 0;i < sizeof(array)/sizeof(int);i++)
	{
		if(hash_set.count(sum - array[i]))	//unordered_set.count()返回指定键值对应的元素数量
		{
			cout << "Found : " << array[i] << ',' <<sum - array[i] <<endl;

		}
		hash_set.insert(array[i]);
	}
	return 0;
}
