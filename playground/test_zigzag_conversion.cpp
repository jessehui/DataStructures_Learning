//
//  test_zigzag_conversion.cpp
//  datastucture_test
//
//  Created by Jesse. on 11/28/16.
//  Copyright © 2016 Jesse. All rights reserved.
//
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
// P   A   H   N
// A P L S I I G
// Y   I   R



/*n=numRows
 Δ=2n-2    1                           2n-1                         4n-3
 Δ=        2                     2n-2  2n                    4n-4   4n-2
 Δ=        3               2n-3        2n+1              4n-5       .
 Δ=        .           .               .               .            .
 Δ=        .       n+2                 .           3n               .
 Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
 Δ=2n-2    n                           3n-2                         5n-4
 */


#include <stdio.h>
#include <iostream>
#include <string>

//如果不需要打印 就注释掉此行
#define DEBUG_ME

using namespace std;

//string convert(string s, int numRows)
//{
//    
//    //string *str = new string("");
//    string result = "";
//    int n = 0;//n是s的iterator
//    int i = 0;//i是result的iterator
//    int row = 0;
//    int flag = 0;
//    int flag2 = 1;
//    
//    
//    if(s.size() == 0)
//        return NULL;
//    
//    while(numRows%2 == 0 && i<=s.size()-1 )//写成偶数行
//    {
//        cout << "i = " << i;
//        cout << "  n = " << n;
//        cout << "  flag2 = " << flag2 <<endl;
//        
//        result[i] = s[n];
//        result = result + result[i];
//        
//        n = n + numRows;
//        if(n>s.size()-1)//该换行了
//        {
//            n = row+1;
//            row++;
//        }
//        
//        
//        i++;
//        cout << "i = " << i;
//        cout << "  n = " << n << endl;
//    }
//    
//    
//    while(numRows%2 == 1 && i<=s.size()-1 )//写成奇数行
//    {
//        if(s[n] == NULL)
//        {
//            cout << "n:" << n;
//            n = row + 1;
//            row++;
//            continue;
//        }
//        if(numRows%2 == 1 && row == numRows/2)	//写成奇数行时 中间那行
//        {
//            
//            result[i] = s[n];
//            n = n + (numRows+1)/2;
//            if(n>s.size())
//            {
//                n = row+1;
//                row++;
//            }
//        }
////        else if(numRows%2 == 0 && row == numRows/2-1)   //写成偶数行时, 中间那行
////        {
////            if(flag == 0)
////            {
////                flag = 1;
////                result[i] = s[n];
////                n = n + (numRows/2) + 1;
////            }
////            else
////            {
////                flag = 0;
////                result[i] = s[n];
////                n = n + (numRows/2);
////            }
////            
////            if(n > s.size())
////            {
////                n = row + 1;
////                row++;
////            }
////        }
//
//        
//        else	//非中间行
//        {
//            result[i] = s[n];
//            n = n+ (numRows+1);
//            if(n>s.size())
//            {
//                n = row+1;
//                row++;
//            }
//        }
//#ifdef DEBUG_ME
//        cout << " i = " << i << endl;
//        cout << result[i] << endl;
//        cout << "n = " << n << endl;
//#endif
//        result = result+result[i];  //???为什么result[i]有值, 而result为空?
//        i++;
//#ifdef DEBUG_ME
//        cout << result <<endl;
//#endif
//        
//    }
//    
//#ifdef DEBUG_ME
//    cout << result <<endl;
//#endif
//    
//    return result;
//    
//    
//}


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


int main ()
{
    string source = "ABCDEF";
    string output = convert(source,4);
    //cout << "source[2] = " << source[24];
    cout << "after convert:" << output << endl;
   // output.~string();
    return 0;
}
