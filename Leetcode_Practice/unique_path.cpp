/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/
class Solution {
public:
    int uniquePaths(int m, int n) {
    	//存储到达该节点有多少种方法
        vector<vector<int>> path(m,vector<int>(n,1));	//init a 2D vector
        for(int i= 1; i<m; i++)
        	for(int j = 1; j < n; j++)
        		path[i][j] = path[i-1][j]+path[i][j-1];

        return path[m-1][n-1];
    }
};

//better solution

class Solution {
public:
    int uniquePaths(int m, int n) {
    }

};