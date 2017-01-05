//
//  Integer_to_Roman.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/5/17.
//  Copyright © 2017 Jesse. All rights reserved.
//
//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



string intToRoman(int num)
{
    string M[] = {"", "M", "MM", "MMM"}; //0-3000
    string C[] = {"", "C", "CC", "CCC", "CD", "D","DC","DCC","DCCC","CM"};   //0-900
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX","LXXX","XC"};    //0-90
    string I[] = {"", "I", "II","III","IV","V","VI","VII","VIII","IX"};     //0-9
    
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[(num%10)];
    
    
}

//Symbol    I	V	X	L	C	D	M
//Value     1	5	10	50	100	500	1,000
int roman(char c)
{
    switch(c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int sum = 0;
    int i=0 ,j = 1;
    while(s[i])
    {
        int left = roman(s[i]);
        int right = roman(s[j]);
        
        if(left<right) //左边的字母小 表示是减去 e.g.IV
            sum = sum - left;
        else
            sum = sum + left;
    
        i++;j++;
        
        cout << "i = " << i << "  ; sum = " << sum << endl;
     }
    
    return sum;
}

int main()
{
    int num = 1042;
    string r = intToRoman(num);
    char c = r[1];
    cout << "string = " << r << endl;
    int check = romanToInt(r);
    cout << "num = " << check << endl;
}
