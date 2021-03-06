/*
Given two sorted integer arrays nums1 and nums2, 
merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater 
or equal to m + n) to hold additional elements from nums2. The number
 of elements initialized in nums1 and nums2 are m and n respectively.

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0;
        int j = 0;

        while(i<m && j < n)
        {
        	if(nums1[i] <= nums2[j])
        	{
        		result.push_back(nums1[i]);
        		i++;
        	}
        	else
        	{
        		result.push_back(nums2[j]);
        		j++;

        	}
        }

        if(i == m)
        {
        	result.insert(result.end(), nums2.begin()+j,nums2.begin()+n);
        }
        else
        	if(j == n)
        {
        	result.insert(result.end(), nums1.begin()+i, nums1.begin()+m);
        }

        nums1 = result;
    }
};