// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
// P   A   H   N
// A P L S I I G
// Y   I   R






class Solution {
public:
    string convert(string s, int numRows)
{
    
    string result = "";
    int n = 0;//n是s的iterator
    int i = 0;//i是result的iterator
    int row = 0;
    bool flag = false;
//    int flag2 = 1;
   // result[i] = s[n];
   
   if(s.size() == 0)
        return result;
        
    if(numRows == 1)
        return s;
    
    while(i <= s.size()-1)
    {
        if(row == 0 || row == numRows-1)    //第0行或者最后一行
            {
                result[i] = s[n];
                result = result + result[i];
                // cout << "i = " << i;
                // cout << "  n = " << n;
                // cout << "  row = " << row;
                // cout << "  result = " << result << endl;
                n = n+(2*numRows - 2);
                if(n>=s.size()) //超过范围 换行
                {
                    n = row+1;
                    row++;
                }
                i++;
            }
            
            else if(row != numRows-1)//如果不是第0行和最后一行
            {
                result[i] = s[n];
                result = result + result[i];
                // cout << "i = " << i;
                // cout << "  n = " << n;
                // cout << "  row = " << row;
                // cout << "  result = " << result << endl;
                if(flag == false)   //斜的数
                {
                    flag = true;
                    n = n+2*numRows-2-2*row;
                 //   cout << "斜的 new n = " << n << endl;
                }
                else
                {
                    flag = false;
                    n = n + 2*row;
                //    cout << "正的 new n = " << n << endl;
                }
                
                if(n>=s.size()) //超过范围 换行
                {
                    n = row+1;
                    row++;
                    flag = false;
                }
                i++;

                
            }
    }
    return result;

        
    
}

};






