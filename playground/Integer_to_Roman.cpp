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

//Symbol    I	V	X	L	C	D	M
//Value     1	5	10	50	100	500	1,000


string intToRoman(int num)
{
    string M[] = {"", "M", "MM", "MMM"}; //0-3000
    string C[] = {"", "C", "CC", "CCC", "CD", "D","DC","DCC","DCCC","CM"};   //0-900
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX","LXXX","XC"};    //0-90
    string I[] = {"", "I", "II","III","IV","V","VI","VII","VIII","IX"};     //0-9
    
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[(num%10)];
    
    
}

int main()
{
    int num = 3012;
    string r = intToRoman(num);
    cout << "string = " << r << endl;
}
