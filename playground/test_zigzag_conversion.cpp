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

#include <stdio.h>
#include <iostream>
#include <string>

//如果不需要打印 就注释掉此行
#define DEBUG_ME

using namespace std;

string convert(string s, int numRows)
{
    
    //string *str = new string("");
    string result = "";
    int n = 0;//n是s的iterator
    int i = 0;//i是result的iterator
    int row = 0;
    int flag = 0;
    
    
    
    
    while(i<=s.size() && n <= s.size())
    {
        if(s[n] == NULL)
        {
            cout << "n:" << n;
            n = row + 1;
            row++;
            continue;
        }
        if(numRows%2 == 1 && row == numRows/2)	//写成奇数行时 中间那行
        {
            
            result[i] = s[n];
            n = n + (numRows+1)/2;
            if(n>s.size())
            {
                n = row+1;
                row++;
            }
        }
        else if(numRows%2 == 0 && row == numRows/2-1)   //写成偶数行时, 中间那行
        {
            if(flag == 0)
            {
                flag = 1;
                result[i] = s[n];
                n = n + (numRows/2) + 1;
            }
            else
            {
                flag = 0;
                result[i] = s[n];
                n = n + (numRows/2);
            }
            
            if(n > s.size())
            {
                n = row + 1;
                row++;
            }
        }
        
        else	//非中间行
        {
            result[i] = s[n];
            n = n+ (numRows+1);
            if(n>s.size())
            {
                n = row+1;
                row++;
            }
        }
#ifdef DEBUG_ME
        cout << " i = " << i << endl;
        cout << result[i] << endl;
#endif
        result = result+result[i];  //???为什么result[i]有值, 而result为空?
        i++;
#ifdef DEBUG_ME
        cout << result <<endl;
#endif
        
    }
    
#ifdef DEBUG_ME
    cout << result <<endl;
#endif
    
    return result;
    
    
}

int main ()
{
    string source = "AB";
    string output = convert(source,1);
    //cout << "source[2] = " << source[24];
    cout << "after convert:" << output << endl;
   // output.~string();
    return 0;
}
