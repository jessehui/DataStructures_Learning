#include <stdio.h>
#include <iostream>
#include <utility>  //swap
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int target = nums.size()-1;
    int current_max = 0;
    for(int i = 0; i <= current_max && i<= target; i++)
    {
        current_max = std::max(nums[i]+i, current_max);
        if(target <= current_max)
            return true;
    }
    return false;
    
}

int main()
{
    vector<int> test = {1,0,2};
    if(canJump(test))
        cout << "True" << endl;
    else cout << "false" << endl;
    
    return 0;
}