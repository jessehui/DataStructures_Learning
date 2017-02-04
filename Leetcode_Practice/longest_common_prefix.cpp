/*
Write a function to find the longest 
common prefix string amongst an array of strings.

*/


//One pass ! Well done
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<1)
        	return "";
        string result = strs[0];

        for(int i = 1; i<strs.size(); i++)
        {
        	int temp = 0;
        	while(temp < min(strs[i].size(),result.size()) && strs[i][temp] == result[temp])
        	{
        		temp++;
        	}
        	result = result.substr(0, temp);
        }

        return result;
    }
};



