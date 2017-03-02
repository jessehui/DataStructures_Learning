/*

Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

*/




// right direction but messy
class Solution {
public:
	
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        unordered_set<int> candi;
        sort(candidates.begin(), candidates.end());
        int min = candidates[0];

        for(int i = 0 ; i<candidates.size(); i++)
        {
        	candi.insert(candidates[i]);
        }

        for(int i = 0; i<candidates.size(); i++)
        {
        	vector<int> temp(1, candidates[i]);

        }


    }
private:
	vector<int> combination(vector<int> origin, unordered_set<int> candi, int target, int min)
	{
		if(candi.count(target))
		{
			origin.push_back(target);
			return origin;
		}

		else
		{
			for(it i = candi.begin(); i!=candi.end; i++)
			{
				vector<int> temp = origin;
				temp.push_back(*it);
				if(target-i < min)
					continue;
				return combination(temp, candi, target-i, min);
			}
		}
	}
};



//another try
class Solution {
public:
	
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> temp;
		vector<vector<int>> result;
		backtracking(candidates, temp, result, target, 0);
		return result;
	}

private:
	void backtracking(vector<int> &candidates, vector<int> temp, \
		vector<vector<int>>&result, int target, int index)
	{
		if(target<0)
			return;
		if(target == 0)
		{
// 		    cout << "target = 0; temp = ";
// 		    for(auto it = temp.begin(); it!=temp.end(); it++)
// 				cout << *it << " ,";
// 			cout << " end " << endl;
    		result.push_back(temp);
			return;
		}

		for(int i = index; i<candidates.size(); i++)
		{
			temp.push_back(candidates[i]);
			backtracking(candidates, temp, result, target - candidates[i], i);
// 			cout << "after backtracking: " ;
// 			for(auto it = temp.begin(); it!=temp.end(); it++)
// 				cout << *it << " ,";
// 			cout << endl;
			temp.pop_back();
		}

	}

};


