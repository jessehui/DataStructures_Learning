//
//  test_stringstream.cpp
//  datastucture_test
//
//  Created by Jesse. on 2/5/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
//#include <boost/algorithm/string.hpp>


using namespace std;


int main()
{
    string a = "1111";
    char *b = "10101";
    int result;
    result = atoi(a.c_str());
    int result2 = atoi(b);
    cout << "result = " << result2 << endl;
    return 0;
}



int main2()
{
    string str("Split me by whitespaces");
    string buf; // Have a buffer string
    stringstream ss(str); // Insert the string into a stream
    
    vector<string> tokens; // Create vector to hold our words
    
    while (ss >> buf)
        tokens.push_back(buf);
    
    for(auto it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
