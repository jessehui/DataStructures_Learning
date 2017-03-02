/*
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]


*/


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        set<vector<int>> result;
        backtracking(candidates, temp, result, target, 0);
        vector<vector<int>> final;
        for(auto it = result.begin(); it != result.end(); it++)
        {
            final.push_back(*it);
        }
        return final;
    }


private:
	void backtracking(vector<int>& candidates, vector<int> &temp, \
		set<vector<int>>& result, int target, int index)
	{
		if(target < 0)
			return;
		if(target == 0)
		{
		    vector<int> temp2 = temp;
		    sort(temp2.begin(), temp2.end());
			result.insert(temp2);
			return;
		}
		for(int i = index; i<candidates.size(); i++)
		{
			// if(index > 0 && candidates[i] == candidates[i-1])
			// 	continue;
			temp.push_back(candidates[i]);
			backtracking(candidates, temp, result, target - candidates[i], i+1);
// 			cout << "after backtracking: " ;
// 			for(auto it = temp.begin(); it!=temp.end(); it++)
// 				cout << *it << " ,";
// 			cout << endl;
			temp.pop_back();
		}
	}
};















