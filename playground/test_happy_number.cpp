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



int main()
{
    int test = 2;
    cout << " is " << test << " happy number? " << "  ";
    cout << isHappy(test) << endl;
    
    return 0;
}
