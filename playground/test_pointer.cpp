//
//  test_pointer.cpp
//  datastucture_test
//
//  Created by Jesse. on 11/27/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//因为本身函数参数是地址, 所以只用交换不行, 要加上引用
void swap(string *&p1, string *&p2)
{
    
    string *new_s = p1;
    p1 = p2;
    p2 = new_s;
    cout << "str1 : " << *p1 << endl;
    cout << "str2 : " << *p2 << endl;
}

int main()
{
    string str1 = "hello world";
    string *p1 = &str1;
    string str2 = "what the hell";
    string *p2 = &str2;
    swap(p1, p2);
    cout << "str1 : " << *p1 << endl;
    cout << "str2 : " << *p2 << endl;
    return 0;
}

//str1 : what the hell
//str2 : hello world
//str1 : what the hell
//str2 : hello world
//Program ended with exit code: 0
