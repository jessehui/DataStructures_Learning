/*

Given an array S of n integers, find three integers in S such that 
the sum is closest to a given number, target. Return the sum of the three 
integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

//[-1,0,1,1,55]
//3
//expected:2
//output: 0

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        sort(nums.begin(),nums.end());
        int temp_rem = INT_MAX;

        for(int i = 0;i < nums.size(); i++)
        {
        	int front = i+1;
        	int back = nums.size()-1;

        	while(front < back)
        	{
	        	int sum = nums[i] + nums[back] + nums[front];
	        	if(sum == target)
	        		return target;

	        	int rem = target - sum;
	        	if(rem > 0)	// sum < target
	        	{
	        		front++;
	        	}
	        	else
	        		back--;

	        	if(abs(rem) < temp_rem)	//difference is smaller
	    		{
	    			temp_rem = abs(rem);
	    			result = sum;
	    		}

	    		while(front < back && nums[front]==nums[front+1])
	    			front ++;

	    		while(front < back && nums[back] == nums[back-1])
	    			back--;
	    	}

	    	while(i<nums.size()-1 && nums[i] == nums[i+1])
	    		i++;

        }

        return result;



    }
};

//Accepted Slow 18%

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        sort(nums.begin(),nums.end());
        int temp_rem = INT_MAX;

        for(int i = 0;i < nums.size(); i++)
        {
        	int front = i+1;
        	int back = nums.size()-1;

        	while(front < back)
        	{
	        	int sum = nums[i] + nums[back] + nums[front];
	       // 	if(sum == target)
	       // 		return target;

	        	int rem = target - sum;
	        //	cout << "rem =  " << " ";
	        	if(rem > 0)	// sum < target
	        	{
	        		front++;
	        	}
	        	else
	        		back--;

	        	if(abs(rem) < temp_rem)	//difference is smaller
	    		{
	    			temp_rem = abs(rem);
	    			result = sum;
	    	//		cout << "sum = " << sum << endl;
	    		}

	   // 		while(front < back-1 && nums[front]==nums[front+1])
	   // 			front ++;

	   // 		while(front < back-1 && nums[back] == nums[back-1])
	   // 			back--;
	    	}

	    	while(i<nums.size()-1 && nums[i] == nums[i+1])
	    		i++;

        }

        return result;



    }
};
