// Suppose an array sorted in ascending order is rotated at some 
//pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in 
//the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.



class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<1)
            return -1;
        // if(nums.size() == 1)
        // {
        //     if(target == nums[0])
        //         return 0;
        //     else return -1;
        // }
        int pivot = -1;
        for(int i = 0; i< nums.size()-1; i++)	//get pivot
        {
        	if(nums[i+1] < nums[i])
        		pivot = i;
        }
    //    cout << "pivot = " <<pivot << endl;
        if(pivot != -1 && (target>nums[pivot] || target < nums[pivot+1]))
            return -1;
        
  //      cout << "test" << endl;

        int left, right;
        if(pivot == -1)
        {
            left = 0;
            right = nums.size()-1;
            goto Binary_Search;
        }
        if(target < nums[0])
        {
        	left = pivot+1;
        	right = nums.size()-1;
        }
        else if(target > nums[0])
        {
        	left = 1;
        	right = pivot;
        }
        else
        	return 0;
        
  //      cout << left << " " << right << " ";

Binary_Search:
        while(left < right-1)	//use binary search
        {
        	int middle = (left+right)/2;
        	if(target == nums[middle])
        	{
        		return middle;
        	}
        	else if(target > nums[middle])
        	{
        		left = middle;
        	}
        	else
        		right = middle;
        }

        if(nums[left] == target)
        	return left;
        else if(nums[right] == target)
        	return right;

        else
        	return -1;
    }
};
