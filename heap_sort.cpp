#include <iostream>
#include "binary_heap.h"

using namespace std;

//堆排序. 堆本身的顺序并不是严格的从大到小或者从小到大 
//但是每次取根节点 一定是按照从大到小或者从小到大的顺序
void heap_sort(int a[], int length)
{
	min_binary_heap<int> heap;
	for(int i = 0; i < length; i++)
		heap.insert(a[i]);	//插入元素 并按照堆的规则排列

	for(int i = 0; i < length; i++)
	{
		a[i] = heap.root();
		heap.delete_root();	//delete完会重新heapify
	}
}

int main()
{
	int a[] = {3, 4, 2, 1, 7, 5, 6, 7, 2, 0};
	heap_sort(a,10);	
	for(int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;

}





