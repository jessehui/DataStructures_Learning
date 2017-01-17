//
//  test_search_for_a_range.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/17/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//For example,
//Given [5, 7, 7, 8, 8, 10] and target value 8,
//return [3, 4].
vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return {-1,-1};
    
    if(nums.size()  == 1)
    {
        if(nums[0] == target)
            return {0,0};
        return {-1,-1};
    }
    
    size_t start = 0;
    size_t end = nums.size()-1;
    size_t find = nums.size()/2;
    while(start < end)
    {
        if(nums[find] < target)
        {
            cout << "dead0 " << endl;
            if(find == start)
            {
                start++;
                continue;
            }
            start = find;
            find = (end+start)/2;

        }
        else if(nums[find] > target)
        {
            cout << "dead1 " << endl;
            end = find;
            find = (end+start)/2;
        }
        else if(nums[find] == target)
        {
            cout << "dead2 " << endl;
            if(nums[start] != target)
                start++;
            if(nums[end] != target)
                end--;
            
            if(nums[start] == target && nums[end] == target)
                break;
            find = (end+start)/2;
        }
    }
    if(start == end)
    {
        if(nums[start] != target)
            return {-1,-1};
    }
    
    return {(int)start,(int)end};
}


int main()
{
    vector<int> test = {1,5};
    vector<int> result = searchRange(test, 4);
    for(vector<int>::iterator it = result.begin(); it != result.end() ; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}
