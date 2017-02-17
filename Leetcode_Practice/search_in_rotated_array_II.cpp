/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at 
some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.


*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()<1)
        	return false;

        //find pivot
        int pivot = -1;
        for(int i = 1; i<nums.size(); i ++)
        {
        	if(nums[i] < nums[i-1])
        		pivot = i;
        }

      //  cout << "pivot = " << pivot << endl;
        if(pivot != -1 && (target<nums[pivot] || target > nums[pivot-1]))
            return false;
        
    //    cout << "test"<<endl;
        //find the right range for left and right
        int left, right;
        if(pivot == -1)
        {
        	left = 0;
        	right = nums.size() - 1;
        }
        else 
        if(target < nums.back())
    	{
    		left = pivot;
    		right = nums.size() - 1;
    	}
        else
        if(target > nums.front())
        {
        	left = 0;
        	right = pivot-1;
        }
        else
        if(target == nums.back() || target == nums.front())
            return true;
        
        else
        return false;
       
        // cout << "left =" << left << " ";
        // cout << "right =" << right << endl;
        //do binary search
        

        while(right > left+1)
        {
        	int middle = (right+left)/2;
        	if(nums[middle] == target)
        		return true;
        	if(nums[middle] < target)
        		left = middle;
        	else
        		right = middle;
        	
      //  	cout << "middle = " <<middle<< endl;
        }

        if(nums[right] == target || nums[left] == target)
        	return true;
        else
        	return false;

    }
};





