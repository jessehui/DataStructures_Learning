/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0)
            return result;
        
        result.push_back({1});
        if(numRows == 1)
            return result;
        
        result.push_back({1,1});
        if(numRows == 2)
            return result;
        
        vector<int> temp;
        
        for(int i = 3; i<= numRows; i++)
        {
            temp.push_back(1);
            generate_vec(temp,result,i);
            temp.push_back(1);
            result.push_back(temp);
            temp.clear();
        }

        return result;
    
    }

private:
    void generate_vec(vector<int>& temp, vector<vector<int>>& result, int num)    
    {
        for(int i = 1; i < num-1; i++)
        {
            temp.push_back(result[num-2][i-1]+result[num-2][i]);
        }
    }
};










