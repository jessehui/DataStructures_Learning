//
//  test_longest_substring.cpp
//  datastucture_test
//
//  Created by Jesse. on 12/13/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;


//int lengthOfLongestSubstring(string s) {
//    vector<char> result;
//    unordered_set<char> hash_set;
//    int max = 0;
//    int temp = 0;   //用于确定index
//    
//    for(int i = 0; i < s.size();i++)
//    {
//        if(hash_set.count(s[i]))	//有重复的 从重复的后边那个重新计算
//        {
//            if(max < result.size())
//                max = result.size();
//            
//            //得到重复的那个元素的index 然后下一次循环就从它的下一个元素开始
//            cout << "temp = " << temp;
//            i = hash_set.bucket(s[i])-1 + temp; //哈希表的index可以说是随机的, 不能用这种方法得到下标
//            
//            cout << "    repeat! then i = " << i << endl;
//            //清零
//            result.clear();
//            hash_set.clear();
//            temp = i+1;
//            
//            
//        }
//        
//        else	//没有重复
//        {
//            result.push_back(s[i]);
//            hash_set.insert(s[i]);
//            cout << "expand ! i = " << i << endl;
//        }
//       // cout << "max = " << max;
//        
//    }
//    
//  //  cout << "result size = " << result.size();
//    if(result.size() > max)
//        max = result.size();
//    
//    return max;
//    
//    
//}

//new method: sliding window
int lengthOfLongestSubstring(string s)
{
    vector<char> result;
    unordered_set<char> hash_set;
    int length=0;
    int max = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        
        if(hash_set.count(s[i]) == 0)
        {
            result.push_back(s[i]);
            hash_set.insert(s[i]);
            length = result.size();
            cout <<" length = " << length << endl;
        }
        
        else
        {
            
            while(hash_set.count(s[i]) == 1)//有重复的元素
            {
                hash_set.erase(*result.begin());
                result.erase(result.begin()); //除去第一个元素
                
                cout << "删除完后 此时result size = " << result.size();
                cout << "删除完后 此时result begin = " << *result.begin();
                cout << " s[i] = " << s[i] ;
                cout << "hash_set.count(s[i]) = " << hash_set.count(s[i]) << endl;
            }
            
            result.push_back(s[i]);
            hash_set.insert(s[i]);
            
        }
        
        if(max < length)
            max = length;
        
    }
    
    return max;
    
}


int main()
{
    string s = "epcdvasvafe";
    int length = lengthOfLongestSubstring(s);
    cout << "length = " << length << endl;
    return 0;
}
