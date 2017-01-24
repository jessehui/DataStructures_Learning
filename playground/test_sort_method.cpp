//
//  test_sort_method.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/23/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <utility>  //swap
#include <vector>

using namespace std;

void quick_sort(int a[], int begin, int end)	//begin end 都是index这里
{
    if(begin >= end)
        return;
    
    int left = begin;
    int right = end;
    int pivot = begin;		//pivot都取最开始的元素
    int pivot_value = a[pivot];	//used to store the value of pivot index
    
    while(left < right)
    {
        if(a[left+1] > pivot_value)
        {
            swap(a[left+1],a[right]);
            right--;
        }
        else	//小于
        {
            a[left] = a[left+1];
            left++;
        }
    }
    
    //把pivot的值赋给left
    a[left] = pivot_value;
    quick_sort(a, begin, left -1);
    quick_sort(a, left+1, end);
    
    
}

bool canJump(vector<int>& nums) {
    int target = nums.size()-1;
    int current_max = 0;
    for(int i = 0; i <= current_max && i<= target; i++)
    {
        current_max = std::max(nums[i]+i, current_max);
        if(target <= current_max)
            return true;
    }
    return false;
    
}

int main()
{
    vector<int> test = {1,0,2};
    if(canJump(test))
        cout << "True" << endl;
    else cout << "false" << endl;
    
    return 0;
}



//int main()
//{
//    int a[] = {3,4,5,1,2,7,32,21,0,4};
//    quick_sort(a, 0, 9);	//end是length-1
//    //quick_sort_wiki_method(a, 0, 9);
//    
//    for(int i = 0;i < 10; i++)
//        cout << a[i] << "  ";
//    cout << endl;
//    return 0;
//}
