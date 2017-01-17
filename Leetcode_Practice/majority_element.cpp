// Given an array of size n, find the majority element. 
//The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.



//hash table method

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result;
        unordered_map<int,int> hash_map;
        for(int i = 0; i<nums.size(); i++)
        {
            hash_map[nums[i]]++;
            if(hash_map[nums[i]] > (nums.size()/2) )
                return nums[i];
        }
        
        return -1;
    }
};



