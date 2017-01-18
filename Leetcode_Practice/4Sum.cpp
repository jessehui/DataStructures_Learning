
//Accepted 但是太繁琐 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> result;
    vector<vector<int>> final_result;
    unordered_set<int> hash_set;
  //  unordered_set<vector<int>> check_repeat;

    
    if(nums.size() == 4 && target == nums[0]+nums[1]+nums[2]+nums[3])
    {
        final_result.push_back(nums);
        return final_result;
    }
    else
    if(nums.size() < 4)
        return final_result;
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size();i++)
    {
        for(int j = i+1; j< nums.size();j++)
        {
            for(int k = j+1; k < nums.size();k++)
            {
                if(k==j || k == i || i==j)
                    continue;
                if(hash_set.count(target-nums[i]-nums[j]-nums[k])==1)   //count return only 0 or 1
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
                
            }
        }
        hash_set.insert(nums[i]);
    }
    
    return final_result;
}
};




//