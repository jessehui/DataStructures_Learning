// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

//brutal-force solution
class Solution {
//运行时间过长 当输入很大的时候
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1; j<nums.size();j++)
            {
                if(nums[i]+nums[j] == target && i != j)
                {    
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        //no answer
        result.push_back(-1);
        return result;
    }
};



//能找到, 时间复杂度为O(n),问题是找不到原来的index了, 因为排序把所有顺序都打乱了
#include <algorithm>
bool compare(int a, int b)
    {
        return a<b;     //升序 ascending order 
    }
    
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int last = nums.size()-1;
        std::sort(nums.begin(),nums.end(),compare);//sort first 
        vector<int> result;
        int i = 0, j = last;
        int sum;
        while(i != j)
        {    
           
            sum = nums[i] + nums[j];
            if(sum > target)
                j--;
            else if(sum < target)
                i++;
            else
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }

        //no solutions
        result.push_back(-1);
        return result;

        
    }

 };




//用hash表做

#include <unordered_set>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        unordered_set<int> hash_set;
        vector<int>::iterator index;
        for(int i = 0; i < nums.size(); i++)
        {
            if(hash_set.count(target- nums[i])) // >0
            {
                result.push_back(i);
                index = find(nums.begin(),nums.end(), target-nums[i]);
                result.push_back(&*index - &nums[0]);   //已知数字, 找对应的下标
                return result;  
                //cout << "index is : " << *index;
            }
            hash_set.insert(nums[i]);
        }

         //no solutions
        result.push_back(-1);
        return result;
    }

};

























