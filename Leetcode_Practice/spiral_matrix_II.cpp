/*

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]


*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int num) {
		int row_start = 0,  row_end = num-1;
		int col_start = 0,  col_end = num-1;

		vector<int> temp(num,0);
		vector<vector<int>> result(num,temp);

		int m,n;
		int i = 1;
		while(i <= num*num)
		{
			//to the right most
			for(m = row_start, n = col_start; n <= col_end; n++)
			{
		//	    cout << "i = " << i << "  ";
				result[m][n] = i++;
				
			}
			row_start++;

			//to the bottom
			for(m = row_start,n=col_end; m <= row_end; m++)
			{
		//	    cout << "i = " << i << "  ";
				result[m][n] = i++;
				
			}
			col_end--;

			//to the left most
			for(n = col_end, m = row_end; n >= col_start; n--)
			{
	//		    cout << "i = " << i << "  ";
				result[m][n] = i++;
				
			}
			row_end--;

			//to the top
			for(m = row_end, n = col_start; m >= row_start; m--)
			{
	//		    cout << "i = " << i << "  ";
				result[m][n] = i++;
				
			}
			col_start++;
    
    //        cout << endl;



		}

		return result;
    }
};



