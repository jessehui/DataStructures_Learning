#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>        //priority_queue

using namespace std;

template<typename T>
void print_vec(vector<T> vec)
{
    
    for(auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    
    cout << endl;
}
