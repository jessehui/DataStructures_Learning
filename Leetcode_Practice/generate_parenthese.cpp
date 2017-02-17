/*
Given n pairs of parentheses, write a function to generate 
all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    vector<string> result;
    rec_par(result, "", n, 0);
    return result;

    }

    //recursively generate parenthesis
    void rec_par(vector<string>& vec_str, string str, int num_left, int num_right)
    {
    	if(num_left == 0 && num_right ==0)
    	{
    		vec_str.push_back(str);
    		return;
    	}

    	if(num_left>0)
    	{
    		rec_par(vec_str, str+"(", num_left-1, num_right+1);
    	}
    	if(num_right > 0)
    	{
    		rec_par(vec_str, str+")", num_left, num_right-1);
    	}
    }
};