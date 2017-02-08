/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
*/



struct compare{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)    //we need the biggest
    {
        return p1.first < p2.first;
    }
};

class Solution{
public:
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
};





