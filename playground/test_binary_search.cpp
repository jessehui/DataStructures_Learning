//
//  test_binary_search.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/17/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include <climits>
#include <iostream>
#include <stdlib.h>

using namespace std;


int divide(int dividend, int divisor) {
    if(divisor == 0 )
        return INT_MAX;
    
    if(dividend == INT_MIN && divisor != 1)
        return INT_MAX;
    
    if(divisor == 1)
        return dividend;
    else if(divisor == -1)
        return 0-dividend;
    
    int flag = 3;
    if(divisor < 0 && dividend <0)
    {
        flag = 2;
        divisor = 0-divisor;
        dividend = 0 - dividend;
    }
    else
        if(dividend < 0)
        {
            flag = 0;
            dividend = 0-dividend;
        }
        else
            if(divisor < 0)
            {
                flag = 1;
                divisor = 0 - divisor;
            }
    
    
    cout << "flag = " << flag <<endl;
    cout << dividend << endl;
    int result = 1;
    
    while(dividend > 0)
    {
        dividend = dividend - divisor;
        result++;
        if(dividend < 0)
            result--;
    }
    
    switch(flag)
    {
        case 0 :return 0-(result-1);
        case 1 :return 0-(result-1);
        default: return result-1;
    }
}

//int divide2(int dividend, int divisor)
//{
//    if(divisor == 0)
//        return INT_MAX;
//    
//    if(dividend == 0)
//        return 0;
//    
//    
//    if(dividend >=0 && divisor >0)
//    {
//        int result = 0;
//        if(divisor == 1)
//            return dividend;
//        while(dividend > 0)
//        {
//            dividend = dividend - divisor;
//            result++;
//            if(dividend < 0)
//                result--;
//        }
//        return result;
//            
//    }
//    
//    else if(dividend < 0 && divisor > 0)
//        //.....
//}

int divide2(int dividend, int divisor)
{
    long divd = abs(long(dividend));
    long divs = abs(long(divisor));
    long divs_cp = divs;
    long result;
    
    if(dividend == 0)
        return 0;
    
    if(divisor == 1)
        return dividend;
    
    if(divd < divs)
        return 0;
    
    long long flag1 = 0;
//    cout << "long long max = " << LLONG_MAX << endl;
//    flag1 = (long long)1<<31);
//    cout << "flag1 =" << flag1 << endl;
    
   // return 0;
    
    while(divd > divs)
    {
        divs = divs << 1;   //左移1位 相当于乘2
        flag1 ++;
        if(divd < divs)
            flag1--;
    }
    
    cout << "flag1 =" << flag1 << endl;
    long temp = divd - (divs_cp << flag1);    //因为divs本身已经大于divd了, 所以要再除2
    
   // flag1 = (long long)(1<<flag1);  //不对了就
    flag1 = (long long)1<<flag1;
    cout << "flag1 second =" << flag1 << endl;
    
   
    long flag2 = 0;
    while(temp > 0)
    {
        temp = temp - divs_cp;
        flag2++;
        if(temp < 0)
            flag2--;
    }
    
    cout << "flag2 =" << flag2 << endl;
    result = flag1+flag2;
    cout <<"fun result = " << result << endl;
    if(result > INT_MAX)
        return INT_MAX;
    else
        if(result < INT_MIN)
            return INT_MIN;
    
    cout <<"fun result2 = " << result << endl;
    
    if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
        return result;
    
    else return 0-result;
    
    
    
}




int main()
{
   // int test = 2147483648;
   // cout << test << " ";
   // return 0;
    
    int dividend = -2147483648;
    int divisor = -1;
  
    int result = divide2(dividend , divisor);
    cout << "result = " << result << endl;
    return 0;
}
