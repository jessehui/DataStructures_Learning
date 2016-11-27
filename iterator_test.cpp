//
//  test.cpp
//  datastucture_test
//
//  Created by Jesse. on 11/26/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main()
{
    
    vector<int> nums = {9,7,6,8};
    int target = 14;
  //  vector<int> solution;
    twoSum(nums, target);
    //cout
    return 0;
    
}

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    unordered_set<int> hash_set;
    vector<int>::iterator index;
    for(int i = 0; i < nums.size(); i++)
    {
        if(hash_set.count(target- nums[i])) // >0
        {
            result.push_back(i);
            index = std::find(nums.begin(),nums.end(), target-nums[i]);
            //cout << "raw index means : " << index;    //!!wrong
            cout << "variable index's addreass : " << &index << endl;   //iterator的地址
            cout << "*index means : " << *index << endl;    //对应的元素的值 解引用操作
            cout << "&*index means : " << &*index << endl;  //值为*index对应的地址
            cout << "nums[2] = 6 what is &num[2]: " << &nums[2] << endl;
            result.push_back(&*index - &nums[0]);   //已知数字, 找对应的下标
            cout << "index is " << i << " and " << &*index - &nums[0] << endl;
            return result;
            //cout << "index is : " << *index;
        }
        hash_set.insert(nums[i]);
    }
    
    //no solutions
    result.push_back(-1);
    return result;

}
