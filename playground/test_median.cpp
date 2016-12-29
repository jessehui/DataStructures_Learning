//
//  test_median.cpp
//  datastucture_test
//
//  Created by Jesse. on 12/28/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;
bool compare(int a, int b)
{
    return a<b;
}

double getMedian(vector<int>& nums)
{
    double median;
    if(nums.size() == 0)
        return median = 0;
    
    if(nums.size()%2 == 1)//奇数个
    {
        median = (double)nums[nums.size()/2];
    }
    else //偶数个
        median = ((double)nums[nums.size()/2 - 1] + (double)nums[nums.size()/2]) / 2;
    
    return median;
}

//1: 奇数 0:偶数
int odd_or_even(vector<int> nums)
{
    int flag;
    if(nums.size()%2 == 1)
        flag = 1;
    else
        flag = 0;
    return flag;
    
}

void assign(vector<int> &nums1, vector<int>& nums2)
{
    vector<int> temp;
    if(nums2.size()%2 == 1)
    {
        temp = nums2;
        nums2 = nums1;
        nums1 = temp;
    }
    
    
    
}

//一个奇数个,一个偶数个, 按照奇数数组二分,减去大于或小于median的元素, 偶数数组减去相同数目的元素
//两个奇数数组, 按照二分, 减去大于或小于median的元素
//两个偶数数组, 按照二分, 减去不包含要求median的元素左边或者右边的元素

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    
    double median_1, median_2;
    int size1 = nums1.size();
    int size2 = nums2.size();
    cout << "size 1 = " << size1 << ";  size 2 = " << size2 << endl;
    int flag1_oe = odd_or_even(nums1);
    int flag2_oe = odd_or_even(nums2);
    
    if(size1 <= 2 || size2 <= 2 )
    {
        vector<int> temp;
        temp.insert(temp.begin(), nums1.begin(),nums1.end());
        temp.insert(temp.begin(), nums2.begin(),nums2.end());
        sort(temp.begin(),temp.end(),compare);  //升序
        cout << "temp = ";
        for(vector<int>::iterator it = temp.begin(); it!=temp.end(); ++it)
            cout << *it << " ";
        cout << endl;
        return getMedian(temp);
        
    }
    
    
    
    median_1 = getMedian(nums1);
    median_2 = getMedian(nums2);
    
    if(median_1 == median_2)
        return double(median_1);
    
    if( flag1_oe ==  flag2_oe  )//都为奇数个 或者都为偶数个
    {
        cout << "都为奇数个. " << endl;
        vector<int>sub1_left(nums1.begin(), nums1.begin()+size1/2);
        vector<int>sub2_left(nums2.begin(), nums2.begin()+size2/2);
        vector<int>sub1_right(nums1.end()-size1/2 - 1, nums1.end());
        vector<int>sub2_right(nums2.end()-size2/2 - 1, nums2.end());
    }
    
    else//一奇一偶
    {
        assign(nums1,nums2);//nums1 奇 nums2 偶
        if(nums1.size() > nums2.size()) //nums1元素多
        {
            vector<int>sub1_left(nums1.begin(), nums1.end() - size2/2);
            vector<int>sub2_left(nums2.begin(), nums2.begin()+size2/2);
            vector<int>sub1_right(nums1.begin()+size2/2-1, nums1.end());
            vector<int>sub2_right(nums2.end()-size2/2 - 1, nums2.end());
        }
        else //nums2 元素多
        {
            vector<int>sub1_left(nums1.begin(),nums1.begin() + size1/2);
            vector<int>sub2_left(nums2.begin(), nums2.end()-size1/2 - 1);
            vector<int>sub1_right(nums1.end() - size1/2 - 1, nums1.end());
            vector<int>sub2_right(nums2.begin()+size1/2,nums2.end());
            
            
        }
        
    }
    
    
    if(median_1 > median_2)
        return findMedianSortedArrays(sub1_left, sub2_right);
    else
        return findMedianSortedArrays(sub2_left, sub1_right);
    
}





int main()
{
    vector<int> nums2 = {1,2,3,9};
    vector<int> nums1 = {4,5,6,7};
    
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "median = " << median << endl;
    return 0;
}
