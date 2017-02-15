//
//  test_decode_ways.cpp
//  datastucture_test
//
//  Created by Jesse. on 2/14/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include "head.h"

int numDecodings(string s) {
    if(s.size()<1)
        return 0;
    //int result = 0;
    vector<int> ways(s.size(),0);
    ways[0] = 1;	//one number must correspond to a character
    for(int i = 0; i< s.size()-1; i++)
    {
        if(stoi(s.substr(i,2)) <= 26)
        {
            ways[i+1] = ways[i]+1;
        }
        else
            ways[i+1] = ways[i];
    }
    
    return ways.back();
    
}
