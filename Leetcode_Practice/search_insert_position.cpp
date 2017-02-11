/*
Given a sorted array and a target value, return the index if the 
target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int step = nums.size()/2;
        int index = step;
        while(index>=0 && index< nums.size() )
        {
            
        	if(target == nums[index])
        	{
        		return index;
        	}

        	if(target > nums[index])
        	{
        	    cout << "big"<< " ";
        		step /= 2;
        		if(step == 0)
        		{
        		    step++;
        		    return index = index+step;
        		}
        		index = index+step;
        	}
        	else
        	{
        	    cout << "small"<< " ";
        		step /= 2;
        		if(step == 0)
        	    {
        		    step++;
        		    if( index-step == -1)
        		        return 0;
        		    else
        		        return index = index-step+1;
        		}   
        		index = index-step;
        	}
        	
        	cout << "index = " <<index << endl;
        }
        if(index == -1)
            index++;

        return index;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int step = nums.size()/2;	//latter or the middle
        int index = step;
        if(target > nums.back())
        	return nums.size();
        
        if(target < nums[0])
        	return 0;

        while(index>=0 && index < nums.size())
        {
        	if(nums[index] == target)
        		return index;

        	if(target > nums[index])
        	{
        		step /= 2;
        		index = index+step;
        		if(step == 0)
        			index++;
        		if(nums[index]>target && step<=1)
        			return index;
        	}

        	else 
        	{
        		step /= 2;
        		index = index-step;
        		if(step == 0)
        			index--;
        		if(nums[index]<target && step<=1)
        			return index+1;
        	}
        }

        //shouldn't reach hear
        return -1;
    }
};

