#include <stdio.h>
#include <iostream>
#include <utility>  //swap
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int target = nums.size();
    int current_max = 0;
    for(int i = 0; i <= current_max && i<= target-1; i++)
    {
        current_max = std::max(nums[i]+i, current_max);
        if(target <= current_max+1)
            return true;
    }
    return false;
    
}

int main()
{
    //int test2[] = {1,0,2};
    vector<int> test = {1,0,2};	
    if(canJump(test))
        cout << "True" << endl;
    else cout << "false" << endl;
    
    return 0;
}
