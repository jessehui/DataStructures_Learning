#include <iostream>
using namespace std;

//merge two sorted sub-array
//left表示左边序列的第一个元素, right可以看作长度. middle表示序列中间的那个index值
void merge(int array[], int temp[], int left, int middle, int right)
{
	int p_left = left, p_right = middle;	//index 左右数组第一个元素
	int i = left;
	while(p_left < middle || p_right < right)	//是否left到right所有元素都已经放入temp
	{
		if(p_left >= middle)	//左侧已经全部放入
		{
			temp[i] = array[p_right];	
			p_right++;
		}
		else if(p_right >= right)	//右侧已经全部放入
		{
			temp[i] = array[p_left];
			p_left++;
		}
		else if(array[p_left] > array[p_right])
		{
			temp[i] = array[p_right];	//先放小的
			p_right++;
		}
		else
		{
			temp[i] = array[p_left];
			p_left++;
		}

		i++;
	}

	for(int i = left; i < right; i++)	//copy back
		array[i] = temp[i];	

}


//From top to down merge and sort
void merge_sort_recursive(int array[], int temp[], int left, int right)
{
    if(right - left <= 1)	//为空或者只有一个元素
        return;
    int middle = (right+left) / 2;
    merge_sort_recursive(array, temp, left, middle);
    merge_sort_recursive(array, temp, middle, right);
    merge(array, temp, left, middle ,right);
    
}


void merge_sort_recursive(int array[], int length)
{
	int *temp = new int[length];
	merge_sort_recursive(array, temp, 0, length);
	delete []temp;
}


//from down to top 从头到尾 两个两个比较再合并
void merge_sort_non_recursive(int array[], int length)
{
	int *temp = new int[length];
	for(int step = 1; step < length; step = 2*step)
		for(int left = 0; left < length; left = left + 2 * step)
		{
			int middle = min(left+step, length);	//防止index溢出
			int right = min(left+2*step, length);
			merge(array, temp, left ,middle, right);
}		}


int main()
{
    int a[] = { 4,21,32, 132, 121, 0, 66,3,2, 71};
	merge_sort_recursive(a,10);
	for(int i = 0; i<10; i++)
		cout << a[i] << "  ";
	cout << endl;
	return 0;
}




