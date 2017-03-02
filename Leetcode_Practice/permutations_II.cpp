/*

Given a collection of numbers that might contain duplicates,
return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

// Accepted, very slow
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> temp;
        vector<int> copy = nums;
        backtracking(result, temp, nums,copy);
        vector<vector<int>> final;
        for(auto it = result.begin() ; it != result.end(); it++)
        {
            final.push_back(*it);
        }
        return final;
    }

    void backtracking(set<vector<int>>& result, vector<int>& temp, vector<int>& nums, vector<int>& copy)
    {
    	if(temp.size() == nums.size())
    	{
    		result.insert(temp);
    		return;
    	}	


    	
    	for(int i = 0; i<copy.size(); i++)
    	{
    	   // if(i>0 && nums[i] == nums[i-1])
    	   //     continue;
    		temp.push_back(copy[i]);
    		copy.erase(copy.begin()+i);
    		backtracking(result, temp, nums, copy);
//     		cout << "after backtracking: " ;
// 			for(auto it = temp.begin(); it!=temp.end(); it++)
// 				cout << *it << " ,";
// 			cout << endl;
    		copy.insert(copy.begin()+i,temp.back());
    		temp.pop_back();
    	}

    	
    }
};



//bug, need to be fixed
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<int> copy = nums;
        backtracking(result, temp, nums,copy,0);
        //vector<vector<int>> final;
        return result;
    }
    
    int flag = 0;
    void backtracking(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, vector<int>& copy, int index)
    {
    	if(temp.size() == nums.size())
    	{
    		result.push_back(temp);
    		return;
    	}	


    	
    	for(int i = 0; i<copy.size(); i++)
    	{
    	   // if(i > 0 && copy[i] == copy[i-1] && )
    	   //     return;    
            
    		temp.push_back(copy[i]);
    		copy.erase(copy.begin()+i);
    		backtracking(result, temp, nums, copy, i);
    		cout << "after backtracking: " ;
			for(auto it = temp.begin(); it!=temp.end(); it++)
				cout << *it << " ,";
			cout << endl;
   next: 	copy.insert(copy.begin()+i,temp.back());
    		temp.pop_back();
    	}

    	
    }
};