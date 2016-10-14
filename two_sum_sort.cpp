/*
从给的一个数组中, 两两求和, 如果和目标的数相同, 就存下来
*/

#include <iostream>
#include <algorithm>

using namespace std;

void two_sum_naive(int a[], int length, int target)	//要遍历两次数组 很慢
{
	for(int i =0; i< length; i++)
	{
		for(int j = i+1; j<length; j++)
			if(a[i] + a[j] == target)
			{
				cout << "Result found: " << a[i] << "," << a[j] << endl;
			}
	}
}

void two_sum_sorted(int a[], int length, int target)	//复杂度O(n) 但是需要数组排好序
{
	//思路: 从两边向中间取.
	//int mid = length / 2;
	int left = 0;
	int right = length - 1;
	int sum_;

	while(left < right)
	{
		a[left] + a[right] = sum_;
		if( sum_ == target)
		{
			cout << "Result found: " << a[i] << "," << a[j] << endl;
			left++;right--;
		}

		else if(sum_ < target)
		{
			left++;
		}
		else
			right--;
	}
}

int main()
{
	int a = {3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
	sort(a, a+10);	//std::sort
	two_sum_sorted(a, 10, 9);
}

