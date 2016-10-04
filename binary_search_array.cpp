#include <iostream>

using namespace std;

//key: the number we search
//end: length
//return the index of the array
int binary_search(int a[], int key, int begin, int end)
{
	if(begin >= end)
		return -1;	//aray is empty, not found

	int middle = (begin + end) / 2;
	if(a[middle] > key)	//说明在左边
		return binary_search(a, key, begin, middle);    //end不被包含进去
	else if(a[middle] < key)	//在右边
		return binary_search(a, key, middle + 1, end);
	else
		return middle;
}



int main()
{
	int a[] = {1, 3, 5, 7,9};
	for(int i = 0; i < 15; i++)
	{
		cout << "searching " << i << "  " ;
		cout << "position is " << binary_search(a, i, 0, 5) << endl;

	}
	return 0;
}





