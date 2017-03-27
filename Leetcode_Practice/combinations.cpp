/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> element;
        backtracking(n, k, result, element);
        return result;
    }

private:
	void backtracking(int n, int k, vector<vector<int>>& result, vector<int>& element)    
	{
		if(element.size() == k)
		{
			result.push_back(element);
			return;
		}

		for(int i = n; i>0; i--)
		{
			element.push_back(i);
			backtracking(i-1, k, result, element);
			element.pop_back();
		}



	}
};
