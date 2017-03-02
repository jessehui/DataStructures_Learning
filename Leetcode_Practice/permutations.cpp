/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

//wrong. Bug embedded
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        backtracking(result, temp, nums, 0);
        return result;
    }


private:
	void backtracking(vector<vector<int>> &result, vector<int> &temp, vector<int> & nums, int number)
	{
		if(temp.size() == nums.size())
		{
			result.push_back(temp);
			return;
		}
		for(int i = 0;i<nums.size(); i++)
		{
		    if(nums[i] == number)
		        continue;
			temp.push_back(nums[i]);
			backtracking(result, temp, nums, nums[i]);
			cout << "after backtracking: " ;
			for(auto it = temp.begin(); it!=temp.end(); it++)
				cout << *it << " ,";
			cout << endl;
			temp.pop_back();
		}

	}
};



//another try

//bug
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<float> copy;
        for(int i = 0 ;i < nums.size(); i++)
        {
            copy.push_back(float(nums[i]));
            cout << copy[i] << " ";
        }
        cout << endl;
            
        backtracking(result, temp, nums, copy);
        return result;
    }


private:
	void backtracking(vector<vector<int>> &result, vector<int> &temp, vector<int> & nums, vector<float> &copy)
	{
		if(temp.size() == nums.size())
		{
			result.push_back(temp);
			return;
		}
		for(int i = 0;i<nums.size(); i++)
		{
		    if(copy[i] == 1.123)	//just change this number
		    {
		        cout << "test";
		        continue;
		    }
			temp.push_back(copy[i]);
			copy[i] = 1.123; //it is flag used to take the place and do nothing
			cout << "copy[ "<< i << "] = " << copy[i] << " ";
            backtracking(result,temp, nums,copy);
            cout << "after backtracking: " ;
			for(auto it = temp.begin(); it!=temp.end(); it++)
				cout << *it << " ,";
			cout << endl;
		    copy[i] = nums[i];
			temp.pop_back();
		}

	}
};


//another try

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<float> copy;
        for(int i = 0 ;i < nums.size(); i++)
        {
            copy.push_back(float(nums[i]));
            cout << copy[i] << " ";
        }
        cout << endl;
            
        backtracking(result, temp, nums, copy);
        return result;
    }


private:
	void backtracking(vector<vector<int>> &result, vector<int> &temp, vector<int> & nums, vector<float> &copy)
	{
		if(temp.size() == nums.size())
		{
			result.push_back(temp);
			return;
		}
		for(int i = 0;i<nums.size(); i++)
		{
		    if(copy[i] == INT_MIN)	//just change this number
		    {
		        cout << "test";
		        continue;
		    }
			temp.push_back(copy[i]);
			copy[i] = INT_MIN; //it is flag used to take the place and do nothing
			cout << "copy[ "<< i << "] = " << copy[i] << " ";
            backtracking(result,temp, nums,copy);
            cout << "after backtracking: " ;
			for(auto it = temp.begin(); it!=temp.end(); it++)
				cout << *it << " ,";
			cout << endl;
		    copy[i] = nums[i];
			temp.pop_back();
		}

	}
};
