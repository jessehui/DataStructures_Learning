//
//  greateset_common_divisor.cpp
//  datastucture_test
//  goal: find the greatest common divisor(GCD) in various ways
//
//  Created by Jesse. on 10/6/16.
//  Copyright © 2016 Jesse. All rights reserved.
//


#include <stdio.h>
#include <iostream>

using namespace std;

//取余操作比较复杂
int GCD_mod(int a, int b)
{
    if(b == 0)
        return a;
    else
        return GCD_mod(b, a % b);
}

//减法操作取余 收敛速度慢
int GCD_sub(int a, int b)
{
    if(a == b || a == 0)
        return a;
    
    if(a > b)
        return GCD_sub(a-b, b);
        
    else    //a<b
        return GCD_sub(b-a, a);
}

//枚举法
int GCD_iter(int a, int b)
{
    int gcd = 1;
    int m = max(a, b);
    for(int i = 2; i<m; i++)
    {
        if( (a%i == 0) && (b%i == 0) )
            gcd = i;
    }
    return gcd;
}

//二进制移位法 占用资源少
int GCD_bin(int a, int b)
{
    int gcd;
    int min_ = min(a,b);
    int max_ = max(a,b);
    
    if(a == b || min_ == 0)
        return a;
    
    //判断奇偶
    if( (~a & 1) && (~b & 1))   //都是偶数
        gcd = 2 * GCD_bin(a >> 1, b >> 1);    //都除以2. 但是注意这里递归调用的时候返回值要*2 
    else if( (~a & 1) && (b & 1))   //b是奇数
        gcd = GCD_bin(a >> 1, b);
    else if( (a & 1) && (~b & 1))   //a是奇数
        gcd = GCD_bin(a, b >> 1);
    else    //都是奇数
        gcd = GCD_bin(max_-min_, min_);
    
    return gcd;
}

int main()
{
    cout << "Input Two numbers:" << endl;
    int a, b;
    cin >> a >> b;
    int gcd = GCD_bin(a,b);
    cout << "gcd = " << gcd << endl;
    return 0;
    
}





