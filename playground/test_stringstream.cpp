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
}
