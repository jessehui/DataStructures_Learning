//从一个很大的数组中找到最大的k个数
//可以用max_binary_heap 但是需要把所有的元素都放到堆中




#include <iostream>
#include "binary_heap.h"

using namespace std;

void print_top_k(int a[], int n, int k)
{
	min_binary_heap<int> heap;

	for(int i = 0; i < n; i++)//遍历所有元素
	{
		cout << "value" << a[i]  << "is comming. " << endl;
	
		if(heap.size() < k)
			heap.insert(a[i]);	//获取最前边的k个元素 堆化

		else if(a[i] > heap.root())	//root这里是最小的 如果后边的元素比当前堆中最小的元素大
		{
			heap.delete_root();	//删除最小的元素
			heap.insert(a[i]);
		}
	}

	cout << "final result: ";
	heap.dump();

}

int main(){
    int a[] = { 3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
    print_top_k(a, 10, 4);
    
    return 0;
}





