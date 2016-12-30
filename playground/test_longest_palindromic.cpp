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
#include <algorithm>

using namespace std;


//string find_longest_substring(string a, string b)
//{
//    for()
//}

//string longestPalindrome(string s)
//    {
//        string s_prime = s;
//        reverse(s_prime.begin(),s_prime.end());
//        cout << "after reverse :";
//        for(string::iterator it = s_prime.begin();it != s_prime.end(); ++it)
//            cout << *it << " ";
//        cout << endl;
//        vector<char> temp;
//        //int num = 0;
//        
//        //find the common string
//        for(string::iterator it_s = s.begin(); it_s != s.end(); ++it_s)
//            for(string::iterator it_sp = s_prime.begin(); it_sp != s_prime.end(); ++it_sp)
//            {
//                while(*it_s == *it_sp)
//                {
//                    temp.push_back(*it_s);
//                    ++it_s; ++it_sp;
//                    if(it_s == s.end() || it_sp == s_prime.end())
//                    {
//                        cout << "end" << endl;
//                        break;
//                    }
//                    cout << "it_s :" << *it_s << " ;    it_sp: " << *it_sp <<endl;
//                }
//                
//                if(temp.size() == 1)	//就只有一个, 就丢弃
//                    temp.erase(temp.begin(),temp.end());
//                
//                
//            }
//        
//        
//        if(temp.size() <= 1)
//            return NULL;
//        
//        else	//检查是否是回文序列
//        {
//            for(int i = 0; i < temp.size()/2; i++)
//                if(temp[i] == temp[temp.size()-1-i])
//                    continue;
//                else
//                    return NULL;
//            
//            
//            
//        }
//        string return_ = string(temp.begin(),temp.end());
//        return return_;
//        
//        
//}

////return 回文次数
//int expand_center(string s, int i, int& flag)
//{
//    int num = 0;
//    int same_num = 1;
////    if(s[i] == s[i+1] && s[i-1] == s[i+1])
////        goto one_;
//    int temp = i;
////    char middle = s[i]
////    if(s[i] == s[i+1])
////    {
////        while(s[i]==s[i+1])
////        {
////            same_num++;
////            i++;
////        }
////        cout << "same num = " << same_num << endl;
////    }
////    
////    i = temp;
//    if(s[i] == s[i+1] )//中间两个一样
//    {
//        
//        num++;
//        flag = 1;
//        for(int j = 1; j < s.length()-1; j++)
//        {
//            if( (i-j>=0) && (i+j+1<s.length()) && (s[i-j] == s[i+1+j]))
//                num++;
//            else break;
//        }
//        cout << " 中间两个 num = " << num << endl;
//        return num; //(num)*2
//    }
//    
//    else    //中间一个分开 两边一样
//    {
///*one_:*/
//        flag = 0;
//        for(int k = 1; k < s.length()-1; k++)
//        {
//            if( (i-k>=0) && (i+k < s.length()) && (s[i-k] == s[i+k]) )
//                num++;
//            else break;
//            
//        }
//        cout << "中间一个 num = " << num << endl;
//        return num; //2*num+1
//    }
//}
//
//string longestPalindrome(string s)
//{
//    int length = 0;
//    int max_ = 0;
//    int index = 0;
//    int flag = 0;   //判定回文类型 中间是两个还是一个
//    int final_flag = 0;
//    
//    if(s.length() == 1)
//        return s;
//    
//    for(int i = 0; i < s.length()-1;i++)
//    {
//        length = expand_center(s,i,flag);
//        if(length >= max_)
//        {
//            max_ = length;
//            index = i;
//            final_flag = flag;
//        }
//        cout << "i = " << i << "  ";
//        cout << "index = " << index << "   ; max_ =  " << max_ <<"  ;final flag = " << final_flag << endl;
//    }
//    
//    if(final_flag == 1)
//        return s.substr(index+1-max_,max_*2);
//    else
//        return s.substr(index-max_, max_*2+1);
//    
//}

//return the length of the palindrome
int expand_palindrome(string s, int left, int right)
{
    while(left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    cout << "left = " << left << "   ; right = " << right;
    cout << "   palin length =  " << right-1-(left+1)+1 << endl;
    return right - left - 1; // right-1-(left+1)+1
}


string longestPalindrome(string s)
{
    int len,len1, len2, max_ = 0;
    int index = 0;
    int flag = 0;
    int final_ = 0;
    for(int i = 0; i<s.length(); i++)
    {
        len1 = expand_palindrome(s,i, i+1); //中间是两个
        len2 = expand_palindrome(s, i, i);  //中间是1个
        len = max(len1,len2);
        if(len1>len2)
        {
            len = len1;
            flag = 1;
        }
        else
        {
            len = len2;
            flag = 0;
        }
        if(len > max_)
        {
            index = i;
            max_ = len;
            final_ = flag;
        }
        cout << "最大的回文中心是: " << index << "  ; max_ = " << max_ << "  ; final flag = " << final_  << endl;
    }
    
    return s.substr(index-max_/2+final_, max_);
}





int main()
{
    string s = "cccc";
    string longest = longestPalindrome(s);
    cout << "final answer: " << longest << endl;
    return 0;
}
