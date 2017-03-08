/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        for(int i = 0; i< matrix.size(); i++)
        {
        	for(int j = 0 ; j<matrix[0].size(); j++)
        	{
        		temp[j][i] = matrix[i][j];
        	}
        }
        for(int i = 0; i< matrix.size(); i++)
        {
            reverse(temp[i].begin(),temp[i].end());
        }
        matrix = temp;
    }
};


//in-place?
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;

  }
};



