//
//  sort_method.cpp
//  datastucture_test
//
//  Created by Jesse. on 2/21/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include "head.h"



//merge and sort (Divide and Conquer)
void merge(vector<int> &a, vector<int> &temp, int left, int middle, int right)
{
    int p_left = left, p_right = middle;    //start index for two sorted array
    int i = left;
    while(p_left < middle || p_right < right)
    {
        if(p_left >= middle) //左侧全部放入
        {
            temp[i] = a[p_right];
            p_right++;
        }
        else if(p_right >= right)    //右侧全部放入
        {
            temp[i] = a[p_left];
            p_left++;
        }
        else if(a[p_left] < a[p_right])
        {
            temp[i] = a[p_left];    //先放小的
            p_left++;
        }
        else
        {
            temp[i] = a[p_right];
            p_right++;
        }
        
        i++;
    }
    
    for(int i = left; i < right; i++)	//copy back
        a[i] = temp[i];
}





//                        original vector, temporary vector, left index, right index + 1(size)
void merge_sort_recursive(vector<int> &a, vector<int> &temp, int left, int right)
{
    if(right-left <= 1)
    {
        return ;
    }
    int middle = (left+right)/2;
    merge_sort_recursive(a, temp, left, middle);
    merge_sort_recursive(a, temp, middle, right);
    cout << "left = " << left << "  middle = " << middle << "  right = " << right << endl;
    merge(a,temp, left, middle, right);
    
}


void merge_sort_recursive(vector<int> &a)
{
    size_t length = a.size();
    vector<int> temp(length);   //做合并用
    merge_sort_recursive(a, temp, 0, length);
}


void merge_sort_non_recursive(vector<int> &a)
{
    int length = a.size();
    vector<int> temp(length);
    for(int step = 1; step<length; step = step*2)
    {
        for(int left = 0; left < length; left = left + 2*step)
        {
            int middle = min(left+step, length);    //防止溢出
            int right = min(left+2*step, length);
            merge(a, temp, left, middle, right);
        }
    }
}


//quick sort
void quick_sort(vector<int> &a, int begin, int end)
{
    if(end - begin <= 0)
        return;
    
    int left = begin, right = end;
    int pivot = a[left];
    while(left < right)
    {
        if(a[left+1] < pivot)
        {
            a[left] = a[left+1];
            left++;
        }
        else
        {
            swap(a[right], a[left+1]);
            right--;
        }
    }
    a[left] = pivot;    //left = right
    
    //for pivot right and pivot left, do quick sort again
    quick_sort(a,begin, left-1);
    quick_sort(a,left+1, end);
}


//heap sort
void heap_sort(vector<int> &a)
{
    priority_queue<int, vector<int>, greater<int>> nums;    //greater 小顶堆 less 大顶堆
    for(int i = 0; i< a.size(); i++)
    {
        nums.push(a[i]);
    }
    a.clear();
    while(nums.empty()!=true)
    {
        a.push_back(nums.top());
        nums.pop();
    }
    for(int i = 0; i<10; i++)
        cout << a[i] << "  ";
    cout << endl;
}


//bubble sort
void bubble_sort(vector<int> &a)
{
    for(int i = 0; i<a.size(); i++)
    {
        int j = 0;
        for( j = 0; j < a.size()- i; j++)
        {
            if(a[j]<a[j+1] )    //<:descending order; >: ascending order
            {
                swap(a[j],a[j+1]);
            }
        }
        cout << "a[ " << j-1 << " ] = " << a[j-1]<< endl;
    }
    for(int i = 0; i<10; i++)
        cout << a[i] << "  ";
    cout << endl;
}


//main function
int main()
{
    vector<int> a = { 4,21,32, 132, 121, 0, 66,3,2, 71};
    //merge_sort_non_recursive(a);
    quick_sort(a, 0, 9);
    
    for(int i = 0; i<10; i++)
        cout << a[i] << "  ";
    cout << endl;
    heap_sort(a);
    bubble_sort(a);
    return 0;
}

