//
//  synapse_test.cpp
//  datastucture_test
//
//  Created by Jesse. on 2/22/17.
//  Copyright © 2017 Jesse. All rights reserved.
//
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * Complete the function below.
 */
int maxDifference(vector < int > a) {
    if(a.size()<=1)
        return -1;
    int result = -1;
    int mini = a[0];
    //int max = a[1];
    for(int i = 1; i< a.size(); i++)
    {
        if(a[i]-mini > result)
        {
            result = a[i]-mini;
        }
        if(a[i]<mini)
        {
            mini = a[i];
        }
    }
    cout << "result = " << result << endl;
    return result;
    
    
}

#include <stdio.h>
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    
    int _a_size = 0;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _a.push_back(_a_item);
    }
    
    res = maxDifference(_a);
    fout << res << endl;
    
    fout.close();
    return 0;
}
