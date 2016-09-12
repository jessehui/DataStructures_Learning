//
//  fib.cpp
//  datastucture_test
//
//  Created by Jesse. on 9/11/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <iostream>

using namespace std;

int fib(int n)
{
    if(n < 2)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
/*    string str("please input a number:");
    cout << str << endl;
    cin >> n;
    cout << n << endl;
    cout << fib(n) << endl;
 */
    
    for(n = 0; n < 48; n++)
    {
        cout << fib(n) << endl;
    }
}


