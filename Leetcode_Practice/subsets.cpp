/*


Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        int flag = 1;
        int index = 0;
        backtracking(result, temp, nums, flag, index);
        
		while(flag++ < nums.size())
		{
		    index = 0;
		    backtracking(result, temp, nums, flag, index);
		}
        return result;
    }

private:
	void backtracking(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int flag, int index)
	{
		if(temp.size() == flag)
		{
		  //  cout << "temp = " ;
		  //  for(int i = 0; i< temp.size(); i++)
		  //  {
		  //      cout << temp[i] << " ";
		  //  }
		  //  cout << endl;
			result.push_back(temp);
			return;
		}

		for(int i = index; i<nums.size(); i++)
		{
			temp.push_back(nums[i]);
			backtracking(result, temp, nums, flag, i+1);
			temp.pop_back();
		}
		
	//	cout << "temp.size = " << temp.size() << endl;

	}
};










//modified very fast 99.2%

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        int flag = 0;
        int index;
      //  backtracking(result, temp, nums, flag, index);
        
		while(flag++ < nums.size())
		{
		    index = 0;
		    backtracking(result, temp, nums, flag, index);
		}
        return result;
    }

private:
	void backtracking(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int flag, int index)
	{
		if(temp.size() == flag)
		{
			result.push_back(temp);
			return;
		}

		for(int i = index; i<nums.size(); i++)
		{
			temp.push_back(nums[i]);
			backtracking(result, temp, nums, flag, i+1);
			temp.pop_back();
		}

	}
};







