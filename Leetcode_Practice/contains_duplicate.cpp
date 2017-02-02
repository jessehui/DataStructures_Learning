/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least
twice in the array, and it should return false if every element is distinct.
*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<2)
        	return false;

        unordered_set<int> hash;

        for(int i = 0; i<nums.size(); i++)
        {
        	if(hash.count(nums[i]))
        	{
        		return true;
        	}
        	else
        		hash.insert(nums[i]);
        }

        return false;

    }
};