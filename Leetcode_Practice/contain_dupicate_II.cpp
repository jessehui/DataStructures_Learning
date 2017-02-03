/*
Given an array of integers and an integer k, find out whether there are 
two distinct indices i and j in the array such that nums[i] = nums[j] 
and the absolute difference between i and j is at most k.
*/

//works 21/23	TLE too slow
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;

        if(nums.size() > k+1)
		{
	        for(int j = 0; j < nums.size()-k; j++)
	        {
		        for(int i = j; i <= j+k; i++)
		        {
		        	if(hash.count(nums[i]))
		        	{
		        		return true;
		        	}
		        	hash.insert(nums[i]);
		        }
		        hash.clear();
		    }
		}
		else
		{
			for(int i = 0; i< nums.size(); i++)
			{
				if(hash.count(nums[i]))
				{
					return true;
				}
				hash.insert(nums[i]);
			}
		}

	    return false;
    }
};



//very fast 98%
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	unordered_map<int, int> val_pos;	//value to position
    	for(int i = 0; i< nums.size(); i++)
    	{
    		if(val_pos.count(nums[i]))	//repeat exist
    		{
    			if( (i - val_pos[nums[i]])<= k)
    				return true;

    			val_pos[nums[i]] = i;
    		}
    		val_pos[nums[i]] = i;
    	}

    	return false;

    }
};