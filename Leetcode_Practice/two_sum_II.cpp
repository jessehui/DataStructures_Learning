/*
Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution 
and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2



*/

// Accepted very very slow (1%)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result_index;
        if(numbers.size() < 1)
        	return result_index;

        for(int i = 0; i< numbers.size(); i++)
        {
        	int j = numbers.size()-1;
        	if(numbers[i]>0)
        	{
        	    while(numbers[j]>target)
        	        j--;
        	}
        	while(j > i)
        	{
        		if(numbers[i] + numbers[j] == target)
        		{
        			result_index.push_back(i+1);
        			result_index.push_back(j+1);
        			return result_index;
        		}
        		j--;
        	}
        }
        return result_index;
    }
};



//slow
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
  		vector<int> result_index;
        if(numbers.size() < 1)
        	return result_index;

        for(int i = 0; i< numbers.size(); i++)
        {
        	int j = i+1;
        	for(; j < numbers.size(); j++)
        	{
        		if(numbers[i]+numbers[j] == target)
        		{
        			result_index.push_back(i+1);
        			result_index.push_back(j+1);
        			return result_index;
        		}
        		if(numbers[i]+numbers[j] > target)
        			break;
        	}
        }

        return result_index;
  	}
};



//two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
  		vector<int> result_index;
// 		if(numbers.size() < 1)
//         	return result_index;

        int left = 0, right = numbers.size() - 1;
        while(left < right)
        {
        	if(numbers[right]+numbers[left] == target)
        	{
        		result_index.push_back(left+1);
        		result_index.push_back(right+1);
        		return result_index;
        	}
        	if(numbers[right]+numbers[left] > target)
        	{
        		right--;
        	}
        	else
        		left++;
        }

        return result_index;
    }
};




