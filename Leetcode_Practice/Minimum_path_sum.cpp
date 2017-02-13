// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right which minimizes 
// the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //init edge point
        int temp = 0;
        vector<vector<int>> result = grid;
        result[0][0] = grid[0][0];
        for(int i = 0; i<grid[0].size()-1; i++)
        {
        	result[0][i+1] = result[0][i]+grid[0][i+1];
        }
     //   cout << "result[0][end] = " << result[0].back() << endl;

        for(int i = 0; i< grid.size()-1; i++)
        {
        	result[i+1][0] = result[i][0]+grid[i+1][0];
        }
      //  cout << "result[end][0] = " << result.back().front() << endl;

        for(int i = 1; i < grid.size(); i++)
        {
        	for(int j = 1;j<grid[0].size();j++)
        	{
        		result[i][j] = grid[i][j]+min(result[i-1][j], result[i][j-1]);
        	}
        }

        return result.back().back();
    }
};


