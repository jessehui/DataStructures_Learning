/*
Given a m x n matrix, if an element is 0, 
set its entire row and column to 0. Do it in place.
*/



//space: O(mn)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() < 1 || matrix[0].size() < 1)
        	return;
        int size = matrix[0].size();
        vector<int> zeros(size, 0);
        vector<vector<int>> temp = matrix;

        for(int i = 0; i < matrix.size(); i++)
        {
        	for(int j = 0; j < matrix[0].size(); j++)
        	{
        		if(temp[i][j] == 0)
        		{
        			matrix.erase(matrix.begin()+i);
        			matrix.insert(matrix.begin()+i, zeros);	//a row of 0
        			for(int k = 0; k < matrix.size(); k++)
        			{
        				matrix[k][j] = 0;
        			}
        		}
        	}
        }
    }
};


//better performance (94%)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // if(matrix.size() < 1 || matrix[0].size() < 1)
        // 	return;
        int size = matrix[0].size();
        vector<int> zeros(size, 0);
        vector<vector<int>> temp = matrix;

        for(int i = 0; i < matrix.size(); i++)
        {
        	for(int j = 0; j < matrix[0].size(); j++)
        	{
        		if(temp[i][j] == 0)
        		{
        			matrix[i] = zeros;
        			for(int k = 0; k < matrix.size(); k++)
        			{
        				matrix[k][j] = 0;
        			}
        		}
        	}
        }
    }
};

//another method
/*
This method uses the first row and first column of the input
 matrix as an auxiliary arrays to indicate which row and which column is set to 0.

So what we do is: first take care of first row and column
 and store the info about these two in two flag variables rFlag and cFlag.

Here is the Algorithm,
1) Scan the first row and set a variable rFlag to indicate
 whether we need to set all 1s in first row or not.

2) Scan the first column and set a variable cFlag to 
indicate whether we need to set all 1s in first column or not.

3) Use first row and first column as the auxiliary
 arrays , consider the matrix as submatrix starting from second row and second column.

5) If element at position (i,j) is zero set position (0,j) as 
0 and set position (i,0) as 0.

6) Traverse the matrix excluding first row and first column.
 If either (0,j) or (i,0) is 0 then set position (i,j) as 0.

Finally, using rFlag and cFlag, update first row and first column if needed.


Auxiliary Space: O(1)


*/

