/*Given a sorted array, remove the duplicates in place such that each element 
appear only once and return the new length.

Do not allocate extra space for another array, you must do this in
 place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of 
nums being 1 and 2 respectively. It doesn't matter what you leave
beyond the new length.

*/
//没必要用hash set 

class Solution {
public:
    
int removeDuplicates(vector<int>& nums) {
      int len = 0;
      unordered_set<int> hash;
      if(nums.size() == 0)
	    return len;
    for(int i = 0; i< nums.size(); i++)
    {
	    if(hash.count(nums[i]))
		    continue;
	    else
	    {
		    len++;
		    hash.insert(nums[i]);
	    }
    }
    nums.clear();
    
    for(auto it = hash.begin(); it != hash.end(); it++)
        nums.push_back(*it);
        
    sort(nums.begin(), nums.end());
    
    return len;
		
	
    }
};


//因为它给定的数组一样的都放在一起 所以直接看之前的元素是否一样就可以

int removeDuplicates(vector<int>& nums)
{
    if(nums.size() <= 1)
        return nums.size();

    int len;

    int pos = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[pos] == nums[i])
        {
          //  pos ++;
            continue;
        }
        else
        {
            nums[pos] = nums[i];
            pos++;
        }
    }
    return pos;
}



//不应该用pos = 0初始化 应该用len = 1
//题意不是很清楚 勉强做出 move on


class Solution {
public:
    
int removeDuplicates(vector<int>& nums)
{
    if(nums.size() <= 1)
        return nums.size();

    int len;
    int size = nums.size();
    int i = 0;
    int pos = 0;
    while(i<size)
    {
        while(nums[i] == nums[pos])
        {
            i++;
            if(i>=size)
            {
                return pos+1;
            }
            
        }
        
        pos++;
        nums[pos] = nums[i];
        
    }
    
    return pos;
    
}
};




