/*
Given an array of n positive integers and a positive integer s, 
find the minimal length of a contiguous subarray of which the sum ≥ s. 
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/



// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
// 		if(nums.size()<1)
// 			return 0;
// 		//get index;
// 		int left = 0, right = nums.size()-1;  
// 		while(left <= right) 
// 		{
// 			int sum = 0;
// 			for(int i = left; i<=right; i++)
// 			{
// 				sum += nums[i];
// 			}

// 			if(sum == s)
// 				return (right-left)+1;
// 			if(sum > s)
// 			{
// 				if(nums[left]<=nums[right])
// 					left++;
// 				else
// 					right--;
// 			}
// 			if(sum < s)
// 			{

// 			}
// 		}
//     }
// };


//right direction but not accepted 10/16
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()<1)
 			return 0;

 		int left = 0, right = 0;
 		int sum = nums[left];
 		int min_num = 1;
 		while(right <= nums.size()-1)
 		{
 		    
 		    if(nums[right] >= s)
 		        return 1;
 			if(sum <= s)
 			{
 			    right ++;
 			    if(right == nums.size())
 		         break; 
 				sum += nums[right];
 			}

 			else if(sum > s)
 			{
 			    if(right - left <= min_num)
 			    {
 			        right++;
 			        break;
 			    }
 				if(sum-nums[left]>=s)
 				{
 					sum -= nums[left];
 					left++;

 				}
 				else
 				{
 				    ++right;
 				    if(right == nums.size())
 		                 break;
 					sum += nums[right];
 				}
 			}
 			
 			cout << "left = " << left << " ";
 			cout << "right = " << right << " ";
 			cout << "sum = " << sum << endl;
 			
 		}

 		if(s <= sum)
 			return (right-1-left)+1;
 		else 
 			return 0;


    }
};


//reconstruction

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()<1)
 			return 0;

 		int left = 0, right = 0;
 		int sum = nums[left];
 		int min_num = nums.size();//store the minimum number of elements whose sum is no smaller than s.
 		while(right <= nums.size()-1)
 		{
 		    
 		    if(nums[right] >= s)
 		        return 1;
 			if(sum <= s)
 			{
 			    right ++;
 			    if(right == nums.size())
 		         break; 
 				sum += nums[right];
 			}

 			else if(sum > s)
 			{
 			    // if(right - left <= min_num)
 			    // {
 			    //     right++;
 			    //     break;
 			    // }
 				if(sum-nums[left]>=s)
 				{
 					sum -= nums[left];
 					left++;

 				}
 				else
 				{
 				    ++right;
 				    if(right == nums.size())
 		                 break;
 					sum += nums[right];
 				}
 			}
 			
 			// cout << "left = " << left << " ";
 			// cout << "right = " << right << " ";
 			// cout << "sum = " << sum << endl;
 			
 			if(sum >= s && min_num > right-left)
 			{
 			    min_num = right-left+1;
 			}
 			
 		}

 		if(s <= sum)
 			return min_num;
 		else 
 			return 0;


    }
};








