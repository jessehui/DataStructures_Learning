//
//  test_happy_number.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/31/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include "head.h"

unordered_set<int> repeat_num;

bool isHappy(int n) {
    string s = to_string(n);
    size_t len = s.size();
    int result = 0;
    for(int i=0;i<len;i++)
    {
        result = result + pow((s[i]-'0'),2);
        //      cout << " result  = " << result << endl;
    }
    if(repeat_num.count(result)>0)
        return false;
    
    if(result == 1)
        return true;
    else
    {
        repeat_num.insert(result);
        return isHappy(result);
    }
}



int countPrimes(int n) {
    int count = 0;
    if(n <= 1)
        return count;
    vector<bool> number(n,true);
    
    for(int i = 2; i*i <= n; i++)   //just need to check  number<sqrt(n)
    {
        if(!number[i])
            continue;
        for(int j = i*i; j < n; j+=i)
        {
            number[j] = false;
            cout << "not prime numbers: " << j << " ";
        }
        cout << endl;
    }
    
    
    for(int i = 2; i<n; i++ )
    {
        if(number[i] == true)
        {
            count ++;
            cout << " prime numbers " << i << " ";
        }
    }
    cout << endl;
    return count;
    
}



int main()
{
    int test = 6;
    cout << "count primes = " << countPrimes(test);
    cout << endl;
    return 0;
}
