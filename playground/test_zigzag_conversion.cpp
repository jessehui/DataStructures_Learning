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

using namespace std;

string convert(string s, int numRows)
{
    
    string *str = new string("");
    string result = *str;
    int n = 0;//n是s的iterator
    int i = 0;//i是result的iterator
    int row = 0;
    
    
    
    
    while(i<s.size())
    {
        if(row == numRows/2)	//中间那行
        {
            result[i] = s[n];
            n = n + (numRows+1)/2;
            if(n>s.size())
            {
                n = row+1;
                row++;
            }
        }
        
        else	//非中间行
        {
            result[i] = s[n];
            n = n+ (numRows+1) + row;
            if(n>s.size())
            {
                n = row+1;
                row++;
            }
        }
        
        cout << " i = " << i << endl;
        cout << result[i] << endl;
        i++;
        
        
        
    }
    cout << "return" <<endl;
    return result;
    
    
}

int main ()
{
    string source = "PAYPALISHIRING";
    string output = convert(source,5);
    cout << output << endl;
    return 0;
}
