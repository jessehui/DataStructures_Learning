/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<1 || nums2.size()<1)
        	return {};

        vector<int> result;
        set<int> temp;
        unordered_set<int> intersec_nums;
        for(int i = 0; i < nums1.size(); i++)
        {
        	intersec_nums.insert(nums1[i]);
        }

        for(int i = 0; i<nums2.size(); i++)
        {
        	if(intersec_nums.count(nums2[i]))
        	{
        		temp.insert(nums2[i]);
        	}
        }
        for(auto it = temp.begin() ; it != temp.end(); it++)
        	result.push_back(*it);

        return result;

    }
};