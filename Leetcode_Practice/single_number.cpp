//Given an array of integers, every element appears twice except for one. 
//Find that single one.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	if(nums.size()<=1)
    		return nums[0];

        unordered_set<int> numbers;
        vector<int> re_num;	//repeat numbers

        for(int i = 0; i<nums.size(); i++)
        {
        	if(!numbers.count(nums[i]))
        	{
        		numbers.insert(nums[i]);
        	}
        	else
        		re_num.push_back(nums[i]);
        }

        for(int j = 0; j<re_num.size(); j++)
        {
        	if(numbers.count(re_num[j]))
        		numbers.erase(re_num[j]);
        }

        auto it = numbers.begin();
        return *it;
    }
};


//Trick solution
//The trick is: A^B^A=B


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int first = nums[0];
        for(int i = 1; i<nums.size();i++) {
            first = first ^ nums[i];
        }
        return first;
    }
};