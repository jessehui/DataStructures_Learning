/*
Now consider if some obstacles are added to the grids. How many unique 
paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

//mess 26/43 Not correct
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();
    	if(m == 1 && n == 1)
    	{
    	    if(obstacleGrid[0][0] == 0)
    	        return 1;
    	    else
    	        return 0;
    	}
    	
    	if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)
    	    return 0;
        vector<vector<int>> ways_reach(m, vector<int>(n, 1));	//first init all 1
        ways_reach[0][0] = 0;
        //ways_reach[m-1][n-1] = 0;
        int j;
        for(int i = 1; i < m ; i++)
        {
        	for( j = 1; j<n; j++)
        	{
        	    
        		if(obstacleGrid[i-1][j] == 1)
				{
					ways_reach[i-1][j] = 0;
					//continue;
				}
				if(obstacleGrid[i][j-1] == 1)
				{
					ways_reach[i][j-1] = 0;
				//	continue;
				}
				if(obstacleGrid[i-1][j-1] == 1)
				{
				    ways_reach[i-1][j] = 0;
				    ways_reach[i][j-1] = 0;
				}
				if(obstacleGrid[i][j] == 1)
        	    {
        	        ways_reach[i][j] = 0;
        	        continue;
        	    }
				
        		ways_reach[i][j] = ways_reach[i-1][j]+ways_reach[i][j-1];
        		cout << "ways reach" << i << "-" << j << " = " << ways_reach[i][j] << endl;
        	}

        	
        }

        return ways_reach[m-1][n-1];

    }
};


//other solution

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));		//init all to 0
        dp[1][0] = 1;	//or dp[0][1] = 1; //used for adding
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!obstacleGrid[i - 1][j - 1])	//not 1
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    } 
};

