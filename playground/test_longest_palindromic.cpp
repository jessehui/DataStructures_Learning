//
//  test_longest_palindromic.cpp
//  datastucture_test
//
//  Created by Jesse. on 12/29/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example:

// Input: "babad"

// Output: "bab"

// Note: "aba" is also a valid answer.
// Example:

// Input: "cbbd"

// Output: "bb"


//method 1:
// Reverse SS and become S'S
// ​′
// ​​ . Find the longest common substring between S and S'
//
// ​​ , which must also be the longest palindromic substring.
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string find_longest_substring(string a, string b)
{
    for()
}

string longestPalindrome(string s)
    {
        string s_prime = s;
        reverse(s_prime.begin(),s_prime.end());
        cout << "after reverse :";
        for(string::iterator it = s_prime.begin();it != s_prime.end(); ++it)
            cout << *it << " ";
        cout << endl;
        vector<char> temp;
        //int num = 0;
        
        //find the common string
        for(string::iterator it_s = s.begin(); it_s != s.end(); ++it_s)
            for(string::iterator it_sp = s_prime.begin(); it_sp != s_prime.end(); ++it_sp)
            {
                while(*it_s == *it_sp)
                {
                    temp.push_back(*it_s);
                    ++it_s; ++it_sp;
                    if(it_s == s.end() || it_sp == s_prime.end())
                    {
                        cout << "end" << endl;
                        break;
                    }
                    cout << "it_s :" << *it_s << " ;    it_sp: " << *it_sp <<endl;
                }
                
                if(temp.size() == 1)	//就只有一个, 就丢弃
                    temp.erase(temp.begin(),temp.end());
                
                
            }
        
        
        if(temp.size() <= 1)
            return NULL;
        
        else	//检查是否是回文序列
        {
            for(int i = 0; i < temp.size()/2; i++)
                if(temp[i] == temp[temp.size()-1-i])
                    continue;
                else
                    return NULL;
            
            
            
        }
        string return_ = string(temp.begin(),temp.end());
        return return_;
        
        
}


int main()
{
    string s = "abbcdcb";
    string longest = longestPalindrome(s);
    cout << "final answer: " << s << endl;
    return 0;
}
