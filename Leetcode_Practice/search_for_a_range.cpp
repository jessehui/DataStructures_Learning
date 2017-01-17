class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return {-1,-1};
    
    if(nums.size()  == 1)
    {
        if(nums[0] == target)
            return {0,0};
        return {-1,-1};
    }
    
    size_t start = 0;
    size_t end = nums.size()-1;
    size_t find = nums.size()/2;
    while(start < end)
    {
        if(nums[find] < target)
        {
       //     cout << "dead0 " << endl;
            if(find == start)
            {
                start++;
                continue;
            }
            start = find;
            find = (end+start)/2;

        }
        else if(nums[find] > target)
        {
      //      cout << "dead1 " << endl;
            end = find;
            find = (end+start)/2;
        }
        else if(nums[find] == target)
        {
       //     cout << "dead2 " << endl;
            if(nums[start] != target)
                start++;
            if(nums[end] != target)
                end--;
            
            if(nums[start] == target && nums[end] == target)
                break;
            find = (end+start)/2;
        }
    }
    if(start == end)
    {
        if(nums[start] != target)
            return {-1,-1};
    }
    
    return {(int)start,(int)end};
}

};