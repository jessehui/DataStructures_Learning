/*
Implement next permutation, which rearranges 
numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, 
it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the 
left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // vector<int> temp = nums;
        // sort(temp.begin(), temp.end());

        int i = nums.size()-1;
        while(i >= 1 && nums[i] <= nums[i-1] )
        {
        	i--;
        }

        if(i == 0)
        {
        	sort(nums.begin(), nums.end());
        	return;
        }

        int flag = i-1;
     //   cout << "flag = " << flag << endl;
        int diff = INT_MAX; //make it the smallest
        while(i<nums.size() && nums[i]-nums[flag] <= diff && nums[i]-nums[flag] > 0)
        {
                diff = nums[i] - nums[flag];
                i++;
        }
 //       cout << "i-1 = " << i-1 << endl;
        swap(nums[flag],nums[i-1]);
        
        sort(nums.begin()+flag+1, nums.end());


    }
};

