/*

Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*/

//bad attemp 132/136 accepted. Data mess. Need reconsitution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() < 1 || matrix[0].size()<1 || target < matrix[0][0] || target > (matrix.back()).back())
            return false;
            

        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        int flag1 = 0;
        int flag2 = 0;
        double step_r = row/2.0;
        double step_c = col/2.0;
        // if(row == 0)
        // {
        //   //  row++;
        //     flag1++;
        // }
        // if(col == 0)
        //     flag2 = 1;
        int c = col;
        if(target > matrix[row/2][0])
        {
            cout << "bigger" << " ";
            row = row/2;
            step_r = floor(step_r)/2.0;
        //  cout << (row < matrix.size()-1)  << " ? " << endl;
            while(row < matrix.size()-1 && target>matrix[row].back())
            {
                row = row+floor(step_r);
                step_r = step_r/2;
                if(step_r == 0)
                    step_r++;
            }
                
            //get the row number
        }
        else
        {
            cout << "smaller" << " ";
            row = row/2;
            while(row > 0 && target < matrix[row][0])
                row = row - ceil(row/2.0) ; //when row = 1 if no ceiling, endless loop
        }

        cout << "row = " << row << endl;
        
         if(target < matrix[row][0])
             return false;

        if(target > matrix[row][c/2])
        {
            c = c/2;
            step_c = floor(step_c)/2;
            while(c <= col && target >= matrix[row][c])
            {
                if(target == matrix[row][c])
                    return true;
                c = c+floor(step_c);
                step_c = step_c/2;
                if(floor(step_c) == 0)
                    step_c++;
                cout << "c = " << c << endl;
            }
        }
        else    //<
        {
            c = c/2;
            step_c = floor(step_c)/2;
            while(c >= 0 && target <= matrix[row][c])
            {
                if(target == matrix[row][c])
                    return true;
                c = c - floor(step_c);
                step_c = step_c/2;
                if(step_c == 0)
                    step_c++;
            }
        }

        return false;

    }
};





//Accepted but I believe there is bug
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() < 1 || matrix[0].size() < 1 )
            return false;

        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        int r = row/2;
        int c = col/2;
        int step_r = r;
        int step_c = c;

        //find row
        if(target > matrix[r][0])
        {
            cout << "bigger" << endl;
            while(r < row && target > matrix[r].back()) //
            {
                int pre_r = r;
                step_r /= 2;
                if(step_r == 0)
                    step_r++;
                r = r+step_r;
                while(target < matrix[r][0])
                {
                    step_r /= 2;
                    if(step_r == 0)
                        step_r++;
                    r = r-step_r;
                }
                if(r == pre_r)
                    break;

                cout << "r = " << r << " ";
            }

        }
        else
        if(target < matrix[r][0])
        {
            cout << "smaller" << endl;
            while(r > 0 && target < matrix[r][0])
            {
                step_r /= 2;
                if(step_r == 0)
                    step_r++;
                r = r - step_r;
                cout << "r = " << r << " ";
            }
        }
        
        cout<< "we get r = " << r << endl;


        if(target > matrix[r].back() || target < matrix[r].front())
            return false;   //can't find

        if(target >= matrix[r][c])
        {
            cout << "bigger col" << endl;
            while(c <= col && target >= matrix[r][c])
            {
                if(target == matrix[r][c])
                    return true;
                step_c /= 2;
                if(step_c == 0)
                    step_c ++;
                c = c+step_c;
                cout << "c = " << c << " ";
            }

        }

        else
        {
            cout << "small col" << endl;
            while(c >= 0 && target <= matrix[r][c])
            {
                if(target == matrix[r][c])
                    return true;

                step_c /= 2;
                if(step_c == 0)
                    step_c++;
                c = c-step_c;
                cout << "c = " << c <<" ";
            }
        }

        cout << "final c = " << c << endl;
        return false;





        
        //return true;
    }
};





//test case:
//[[-10,-8],[-6,-5],[-2,-2],[-1,0],[3,4],[7,7],[8,9],[10,10],[11,11],[12,14],[15,16],[17,19],[20,21],[22,22],[25,27],[28,30],[32,32],[35,36]]
// 16
//after debugging
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() < 1 || matrix[0].size() < 1 )
            return false;

        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        int r = row/2;
        int c = col/2;
        int step_r = r;
        int step_c = c;

        //find row
        if(target > matrix[r][0])
        {
       //     cout << "bigger" << endl;
            while(r < row && target > matrix[r].back()) //
            {
                int pre_r = r;
                step_r /= 2;
                if(step_r == 0)
                    step_r++;
                r = r+step_r;
                while(target < matrix[r][0])
                {
                    step_r /= 2;
                    if(step_r == 0)
                        step_r++;
                    r = r-step_r;
                }
                if(r == pre_r)
                    break;

         //       cout << "r = " << r << " ";
            }

        }
        else
        if(target < matrix[r][0])
        {
      //      cout << "smaller" << endl;
            while(r > 0 && target < matrix[r][0])
            {
                int pre_r = r;
                step_r /= 2;
                if(step_r == 0)
                    step_r++;
                r = r - step_r;
                while(target > matrix[r].back())
                {
                    step_r /= 2;
                    if(step_r == 0)
                        step_r++;
                    r = r+step_r;
                }
                if(r == pre_r)
                    break;
      //          cout << "r = " << r << " ";
            }
        }
        
  //      cout<< "we get r = " << r << endl;


        if(target > matrix[r].back() || target < matrix[r].front())
            return false;   //can't find

        if(target >= matrix[r][c])
        {
   //         cout << "bigger col" << endl;
            while(c <= col && target >= matrix[r][c])
            {
                int pre_c = c;
                if(target == matrix[r][c])
                    return true;
                step_c /= 2;
                if(step_c == 0)
                    step_c ++;
                c = c+step_c;
                while(target < matrix[r][c])
                {
                    step_c /= 2;
                    if(step_c == 0)
                        step_c++;
                    c = c-step_c;
                }
                if(pre_c == c)
                    break;
      //          cout << "c = " << c << " ";
            }

        }

        else
        {
    //        cout << "small col" << endl;
            while(c >= 0 && target <= matrix[r][c])
            {
                int pre_c = c;
                if(target == matrix[r][c])
                    return true;

                step_c /= 2;
                if(step_c == 0)
                    step_c++;
                c = c-step_c;
                while(target > matrix[r][c])
                {
                    step_c /= 2;
                    if(step_c == 0)
                        step_c++;
                    c = c+step_c;
                }
                if(pre_c == c)
                    break;
        //        cout << "c = " << c <<" ";
            }
        }

  //      cout << "final c = " << c << endl;
        return false;





        
        //return true;
    }
};

