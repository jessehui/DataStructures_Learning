//
//  test_median_two_arrays.cpp
//  datastucture_test
//
//  Created by Jesse. on 12/14/16.
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

int odd_or_even(vector<int> nums)
{
    int flag;
    if(nums.size()%2 == 1)
        flag = 1;
    else
        flag = 0;
    return flag;
    
}

int determin_flag(int flag_nums1, vector<int> nums1, vector<int> nums2)
{
    int flag;
    if(flag_nums1 == 1) //nums1 odd的话
        if(nums1.size()> nums2.size()) //nums1大的话
            return flag = 1;
        else return flag = 0;
    else//偶数个就等于0
        return flag = 0;
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    double median_1, median_2;
    median_1 = getMedian(nums1);
    median_2 = getMedian(nums2);
    int flag1 = determin_flag(odd_or_even(nums1), nums1,nums2); //odd个元素 返回 1
    int flag2 = determin_flag(odd_or_even(nums2), nums2,nums1);
    
    cout << "flag 1 =  " << flag1 << " ";
    cout << "flag 2 =  " << flag2 << " ";
    
    if(nums1.size() <= 2 || nums2.size() <= 2 )
    {
        vector<int> temp;
        temp.insert(temp.begin(), nums1.begin(),nums1.end());
        temp.insert(temp.begin(), nums2.begin(),nums2.end());
        sort(temp.begin(),temp.end(),compare);
         	cout << "temp = ";
         	for(vector<int>::iterator it = temp.begin(); it!=temp.end(); ++it)
         	    cout << *it << " ";
         	cout << endl;
        return getMedian(temp);
        
    }

    
    vector<int>sub1_right (nums1.end() - nums1.size()/2 - flag1, nums1.end());
    vector<int>sub1_left (nums1.begin(), nums1.begin() + nums1.size()/2 + flag1);   //后边的参数相当于end iterator所以要大一个
    vector<int>sub2_right (nums2.end() - nums2.size()/2 - flag2, nums2.end());
    vector<int>sub2_left (nums2.begin(), nums2.begin() + flag2 + nums2.size()/2);//奇数要加1
    
    if(median_1 < median_2)
    {
        return findMedianSortedArrays(sub1_right, sub2_left);
    }
    if(median_1 > median_2)
        return findMedianSortedArrays(sub1_left, sub2_right);
    
    else
        return median_1;
    
    
}


//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//    
//    double median_1, median_2;
//    median_1 = getMedian(nums1);
//    median_2 = getMedian(nums2);
//    int size1 = nums1.size();
//    int size2 = nums2.size();
//    
//    if( (size1+size2)%2 == 1 )
//    {
//        //找最中间的元素即可
//        return find(nums1,nums2);
//    }
//    
//}

int main()
{
    vector<int> nums2 = {1,2,3};
    vector<int> nums1 = {4,5,6,7};
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "median = " << median << endl;
    return 0;
}
