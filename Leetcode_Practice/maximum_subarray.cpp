// Find the contiguous subarray within an array
// (containing at least one number) which has the largest sum.

// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.

#include <algorithm>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
            
        int sum = 0; //
        int max_ = INT_MIN; //last result
        //vector<int> sub;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = sum+nums[i];
            max_ = std::max(max_,sum);
            if(sum < 0)
                sum = 0;
            
        }
        return max_;
    }
};