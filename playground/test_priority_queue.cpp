//
//  test_priority_queue.cpp
//  datastucture_test
//
//  Created by Jesse. on 2/8/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include "head.h"

struct compare{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)    //we need the biggest
    {
        return p1.first < p2.first; //相当于 less 大顶堆
                                    //greater 小顶堆
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    //    int most_fre = 0;
    unordered_map<int, int> num_times;
    //   queue<int> times; //
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> time_num_pri_q;
    
    for(int i = 0; i< nums.size(); i++)
    {
        num_times[nums[i]]++;
    }
    
    for(auto it = num_times.begin(); it != num_times.end(); it++)
    {
        pair<int, int> times_num;
        times_num = make_pair(it->second, it->first);
        time_num_pri_q.push(times_num);
        
    }
    
    for(int i = k; i > 0; i--)
    {
        result.push_back(time_num_pri_q.top().second);
        time_num_pri_q.pop();
    }
    
    return result;
}

int main()
{
    vector<int> vec = {1,1,1,2,2,3};
    vector<int> result = topKFrequent(vec, 2);
    print_vec(result);
    return 0;
}
