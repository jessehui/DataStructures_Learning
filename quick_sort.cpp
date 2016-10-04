#include <iostream>
#include <utility>	//std: swap

using namespace std;


void quick_sort(int a[], int begin, int end)//begin是[0], end是[length-1]
{
	if(begin >= end)	//递归算法一般一开始都会判断一下跳出的条件是否达到
		return;		//只有一个元素(=)或者没有元素(>)

	int left = begin, right = end;
	int pivot_value = a[left];	//轴心都设置为第一个元素

	while(left < right)
	{
		if(a[left+1] < pivot_value)	//小于轴心
		{
			a[left] = a[left+1];	//就放在左边
			left++;		//从最左边开始
		}
		else	//大于轴心
		{
			swap(a[left+1], a[right]);	//放在后边
			right--;	//从最右边开始
		}

	}
	//while循环完后, pivot_value要归位
	a[left] = pivot_value;

	//对轴心两边的数组 recursively call the function 
	quick_sort(a, begin, left-1);
	quick_sort(a, left+1, end); 

}



void quick_sort_wiki_method(int a[], int begin, int end)
{
	//设置跳出条件
	if(begin >= end)
		return;
	int pivot_index = begin;
	int pivot_value = a[pivot_index];

	//轴心一直在begin的位置, 从begin+1开始
	//一开始小于轴心的都不变位置, 因为pivot_index和k同步增长, swap没用
	//直到遇到大于轴心的, 在下一次循环的时候会把大的和小的交换位置, 大的放在右边, 小的放左边
	for(int k = begin + 1; k <= end; k++)
	{
		if(a[k] < pivot_value)
		{
			pivot_index++;
			swap(a[pivot_index], a[k]);	
		}
	}

	//因为轴心一直在begin的位置, 所以最后把轴心换到中间
	swap(a[begin], a[pivot_index]);	

	//然后对轴心两边分别递归
	quick_sort_wiki_method(a, begin, pivot_index - 1);
	quick_sort_wiki_method(a, pivot_index + 1, end);
}



int main()
{
    int a[] = {3,4,5,1,2,7,32,21,0,4};
	//quick_sort(a, 0, 9);	//end是length-1
    quick_sort_wiki_method(a, 0, 9);
    
	for(int i = 0;i < 10; i++)
		cout << a[i] << "  ";
	cout << endl;
	return 0;
}



