/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/


//Not right. Didn't understand the statement
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
        	if( (*it)+(it-nums.begin()) == nums.size()-1 )
        		return true;
        	else
        		continue;

        }
        return false;
    }
};


//As straightforward as it is. Just update the current max position it can reach.
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int target = nums.size()-1;
    	int current_max = 0;
    	for(int i = 0; i <= current_max && i<= target; i++)
        {
        	current_max = max(nums[i]+i, curent_max);
        	if(target <= current_max)
        		return true;
        }
        return false;

    }

};








