/*

Given an array nums, write a function to move all 
0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after 
calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

//Accepted, Not fast enough
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int j = 0;
        for(int i = 0; i<nums.size(); i++)
        {
        	if(nums[i] == 0)
        	{
        		j = i;
        		while(nums[j] == 0 && j<nums.size()-1)
        		{
        			j++;
        		}
        		swap(nums[i], nums[j]);
        		
        		
        	}

        	for(auto it = nums.begin(); it!=nums.end(); it++)
        		cout << *it << " ";
        	cout << endl;
        }
    }
};



//better performance

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int zero = 0, non_zero = 0;
        for(int i = 0; i<nums.size(); )
        {
            
            
        	if(nums[i] == 0)
        	{
        		if(nums[zero]!=0)
        			zero = i;
        		while(i < nums.size()-1 && nums[i] == 0)
        		{
        			i++;
        		}
        		non_zero = i;
        		swap(nums[zero], nums[non_zero]);
        		if(zero < nums.size()-1 && nums[zero+1] == 0)
        			zero++;
        		

        		i = non_zero+1;
        	}
        	else if(nums[zero] == 0)
        	{
        		non_zero = i;
        		swap(nums[zero], nums[non_zero]);
        		i = non_zero+1;
        		if(zero < nums.size()-1 && nums[zero+1] == 0)
        			zero++;
        	}
        	else
        	    i++;

        // 	for(auto it = nums.begin(); it!=nums.end(); it++)
        // 		cout << *it << " ";
        // 	cout << endl;
        }


    }
};


//also works
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int j = 0;
    	vector<int> temp = nums;
        for(int i = 0; i<nums.size(); i++)
        {
        	if(nums[i] == 0)
        	{
        		j = i;
        		while(nums[j] == 0 && j<nums.size()-1)
        		{
        			j++;
        		}
        		swap(nums[i], nums[j]);
        		if(temp == nums)
        		    return;
        		
        	}

        // 	for(auto it = nums.begin(); it!=nums.end(); it++)
        // 		cout << *it << " ";
        // 	cout << endl;
        }
    }
};