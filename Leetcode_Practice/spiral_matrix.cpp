/*
Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return result;
        
        int row_end = matrix.size()-1;
        int col_end = matrix[0].size()-1;
        int num = (row_end+1)*(col_end+1);

        int m = 0, n = 0;
        int col_begin = 0, row_begin = 0;
        

        while(result.size() != num)
        {
            //traverse to the right
            m = row_begin;
            for(n = col_begin; n<=col_end;n++)
            {
                result.push_back(matrix[m][n]);
            }
            row_begin++;
            
            if(result.size() == num)
                break;

            //traverse to the down
            n = col_end;
            for(m = row_begin; m <= row_end;m++)
            {
                result.push_back(matrix[m][n]);
            }
            col_end--;
            
            if(result.size() == num)
                break;

            //traverse to the left
            m = row_end;
            for(n = col_end; n >= col_begin; n--)
            {
                result.push_back(matrix[m][n]);
            }
            row_end--;
            
            if(result.size() == num)
                break;

            //traverse to the up
            n = col_begin;
            for(m = row_end; m >= row_begin; m--)
            {
                result.push_back(matrix[m][n]);
            }
            col_begin++;

        }

        return result;
    }
};





