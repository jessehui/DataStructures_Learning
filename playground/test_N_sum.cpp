//
//  test_N_sum.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/16/17.
//  Copyright © 2017 Jesse. All rights reserved.
//
//可以开始总结mSum问题了：在空间复杂度为O(1)的前提下，除了2sum需要用O(nlogn)的时间复杂度之外，
//mSum问题的时间复杂度一般为O(n^(m-1))。这是因为，在排好序的情况下，
//对前m-2个元素需要进行枚举，而最后2个元素用双指针进行一次扫描即可。注意根据题目要求，每个被枚举的元素都要考虑去重。
//

#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> result;
    vector<vector<int>> final_result;
    unordered_set<int> hash_set;
  //  unordered_set<vector<int>> check_repeat;
    
    if(nums.size() <= 4)
    {
        final_result.push_back(nums);
        return final_result;
    }
    
    sort(nums.begin(),nums.end());
    for(int i = 0;i<nums.size();i++)
    {
        for(int j = 0; j< nums.size();j++)
        {
            for(int k =0; k < nums.size();k++)
            {
                if(hash_set.count(target-nums[i]-nums[j]-nums[k])>0)
                {
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                    result.push_back(nums[k]);
                    result.push_back(target-nums[i]-nums[j]-nums[k]);
                    sort(result.begin(),result.end());
                    if(find(final_result.begin(),final_result.end(),result) == final_result.end())
                    {
                        final_result.push_back(result);
                        result.clear();
                    }
                    else
                        result.clear();
                }
                
                hash_set.insert(nums[k]);
            }
        }
    }
    
    return final_result;
}

//vector<vector<int>> fourSum(vector<int>& nums, int target) {
//
//    vector<vector<int>> final_res;
//    vector<int> result;
//    
//
//}

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char,bool> row;
    unordered_map<char,bool> column;
    unordered_map<char,bool> cell;
    
    for(int i = 0 ;i < 9 ;i++)
    {
        for(int j = 0; j< 9;j++)
        {
            if(board[i][j] != '.')//i行j列
            {
                if(row[board[i][j]] == true)    //true表示已经添加索引了 表示重复
                    return false;
                else
                    row[board[i][j]] = true;    //hash map 引用用[]
            }
            
            
            if(board[j][i] != '.')
            {
                if(column[board[j][i]] == true)
                    return false;
                else
                    column[board[j][i]] = true;
            }
            
            
            //cell是按照一个cell那样排的, 要找到每个九宫格对应的board数组中的值 (0,5) -> (1,2)
            //i j 这里开始表示第i个九宫格第j个元素
            //先确定从board的哪一行取:
            //对于i: 第0,1,2个cell都是从第0行取 3,4,5个cell都是从第三行区, 6,7,8都是第6行取
            //但是还要加上j的偏移: 0,1,2偏移都是0, 3,4,5偏移1行, 678偏移2行
            //再确定从board的哪一列取: 同理
            //
            if(board[(i/3)*3+(j/3)][(i%3)*3+(j%3)] != '.')
            {
                if(cell[board[(i/3)*3+(j/3)][(i%3)*3+(j%3)]] == true)
                    return false;
                else
                    cell[board[(i/3)*3+(j/3)][(i%3)*3+(j%3)]] = true;
            }
            
            
            
        }
        row.clear();
        column.clear();
        cell.clear();
    }
    return true;
}

int main()
{
    vector<int> a = {1,0,-1,0,-2,2};
    fourSum(a, 0);
    return 0;
}


