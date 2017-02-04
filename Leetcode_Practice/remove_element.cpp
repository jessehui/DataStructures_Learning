/*Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.



*/
//accepted not very fast
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
   
        for(int i = 0; i<nums.size();i++)
        {
        	if(nums[i] == val)
        	{
        		swap(nums[i], *(nums.end()-1));
        		nums.pop_back();
        		i--;	//after swap do i again
        	}

        }
        return (int)nums.size();
    }
};


//Accepted but slower.....
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
  		if(nums.size()<1)
  		    return 0;
  		sort(nums.begin(), nums.end());
  		for(int i = 0;i<nums.size();)
  		{
  			if(nums[i] < val)
  			{
  				i++;
  				if(i>=nums.size())
  				    return (int)nums.size();
  			}
  			else if(nums[i] == val)	//delete all the number with the same val
  			{
  				int flag = i;
  				while(flag < nums.size() && nums[flag] == val)
  					flag++;
  				nums.erase(nums.begin()+i,nums.begin()+flag);
  				if(i>=nums.size())
  					return (int)nums.size();
  			}
  			else
  				return (int)nums.size();
  		}

    }
};





