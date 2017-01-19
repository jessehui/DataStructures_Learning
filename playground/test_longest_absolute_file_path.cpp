//
//  test_longest_absolute_file_path.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/19/17.
//  Copyright © 2017 Jesse. All rights reserved.
//
/*
 The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 
 dir
    subdir1
    subdir2
        file.ext
 The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
 
*/


#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

//int lengthLongestPath(string input) {
//    
//}


class Solution {
public:
    int lengthLongestPath2(string input) {
        istringstream ss(input);
        string token;
        size_t max_len = 0;
        unordered_map<int, int> path_len;
        path_len[0] = 0;
        while (getline(ss, token)) {
            auto pos = token.find_last_of("\t");    //如果没有就返回 string::npos(\t,\n这种都算是一个字符)
            string name = (pos != std::string::npos) ? token.substr(pos + 1) : token;   //substr(pos+1)从pos+1到end. 得到该行的文件名字
            
            int depth = token.size() - name.size(); //the number of tabs
            if (token.find(".") != std::string::npos) { //如果token里有.(表示它是一个文件)
                max_len = max(max_len, path_len[depth] + name.size());
            } else {
                path_len[depth + 1] = path_len[depth] + name.size() + 1;    //why +1 ?
            }
        }
        return max_len;
    }
};


/*
 The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 
 dir
    subdir1
    subdir2
        file.ext
 The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
 
 */

int lengthLongestPath(string input)
{
    istringstream instring(input);  //input to stringstream to process
    unordered_map<int,int> path_len;
    path_len[0] = 0;
    string token;   // to store string get each line
    size_t max_len = 0;
    
    while(getline(instring, token))
    {
        auto pos = token.find_last_of("\t");
        string name = (pos != string::npos)? token.substr(pos+1): token;    //get only the name
        //string::npos means the end of the string. used to judge whether there is a match
        size_t depth = token.size() - name.size();  //number of \t
        if(name.find(".") != string::npos)  //it is a file , end of the path
        {
            max_len = max(max_len, path_len[depth] + name.size());
        }
        else
        {
            path_len[depth+1] = path_len[depth] + name.size() + 1;  // why +1 : the actual path is written like "dir/subdir2/subsubdir2/file2.ext"
        
        
    }
    
    return max_len;
}
    





