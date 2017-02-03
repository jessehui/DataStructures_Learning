/*
Given an array S of n integers, are there elements a, b, c 
in S such that a + b + c = 0? Find all unique triplets in the array 
which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

//works well 286/311	but Time Limit Exceeded
//主要是重复的问题没有好的解决

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> result;
    	if(nums.size()<3)
    		return result;
    	vector<int> temp;
    	sort(nums.begin(), nums.end());
    	vector<vector<int>> final;

        unordered_set<int> hash_set;
        for(int i = 0; i<nums.size();i++)
        {
        	for(int j = i+1; j<nums.size();j++)
        	{
        		if(hash_set.count(0-nums[i]-nums[j]))
        		{
        			temp.push_back(nums[i]);
        			temp.push_back(0-nums[i]-nums[j]);
        			temp.push_back(nums[j]);
        			// if(find(result.begin(),result.end(),temp) == result.end())
        			result.push_back(temp);
        			temp.clear();
        		}
        		hash_set.insert(nums[j]);

        	}
        	hash_set.clear();
        }
        if(result.size()<1)
            return result;
            
        sort(result.begin(),result.end());
        auto it = result.begin();
        for(; it < result.end()-1; it++)
        {
        	if((*it) != *(it+1))
        		final.push_back(*it);
        }
        final.push_back(*(it));

        return final;
    }
};



//another approch Accepted (110ms+)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	
    	
    	if(nums.size()<3)
    		return {};
    	vector<vector<int>> final;
    	set<vector<int>> result;
    	vector<int> temp;
    	sort(nums.begin(), nums.end());
    	

        unordered_set<int> hash_set;
        for(int i = 0; i<nums.size();i++)
        {
        	if(i != 0 && nums[i] == nums[i-1])	//jump those duplicate numbers
        			continue;
        	for(int j = i+1; j<nums.size();j++)
        	{
        // 		if(j != i+1 && nums[j] == nums[j-1])
        // 			continue;
        		if(hash_set.count(0-nums[i]-nums[j]))
        		{
        			temp.push_back(nums[i]);
        			temp.push_back(0-nums[i]-nums[j]);
        			temp.push_back(nums[j]);
        			// if(find(result.begin(),result.end(),temp) == result.end())
        			result.insert(temp);
        			temp.clear();
        		}
        		hash_set.insert(nums[j]);

        	}
        	hash_set.clear();
        }
        if(result.size()<1)
            return final;
        
        for(auto it = result.begin();it!=result.end();it++)
        	final.push_back(*it);
        

        return final;
    }
};


//new approach
/*
first, we always check incremently, so when the current target is same as previous, 
we don't need to check it again, this is proceed by:

		if (i>0 && (num[i] == num[i-1]))
			continue;

second, the result sequence is in increase order, so the only duplicated sequence is 
with the previous, it's proceed by:

		if (result.empty())
			result.push_back(sequence);
		else
		{
			vector<int> previous = result.back();
			if (!((previous[0] == sequence[0]) && (previous[1] == sequence[1])))
				result.push_back(sequence);
		}
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	
    	
    	if(nums.size()<3)
    		return {};
    	vector<vector<int>> final;
    	//set<vector<int>> result;
    	vector<int> temp;
    	sort(nums.begin(), nums.end());
    	

        unordered_set<int> hash_set;
        for(int i = 0; i<nums.size();i++)
        {
        	if(i != 0 && nums[i] == nums[i-1])	//jump those duplicate numbers
        			continue;
        	for(int j = i+1; j<nums.size();j++)
        	{
        // 		if(j != i+1 && nums[j] == nums[j-1])
        // 			continue;
        		if(hash_set.count(0-nums[i]-nums[j]))
        		{
        			temp.push_back(nums[i]);
        			temp.push_back(0-nums[i]-nums[j]);
        			temp.push_back(nums[j]);
        			// if(find(result.begin(),result.end(),temp) == result.end())
        			if(final.size() < 1 || temp != final.back())	//
	        			final.push_back(temp);
        			temp.clear();
        		}
        		hash_set.insert(nums[j]);

        	}
        	hash_set.clear();
        }
        // if(final.size()<1)
        //     return final;
        
        // for(auto it = final.begin();it!=result.end();it++)
        // 	final.push_back(*it);
        

        return final;
    }
};