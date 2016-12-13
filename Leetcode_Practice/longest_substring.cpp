/*Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 

Note that the answer must be a substring, 

"pwke" is a subsequence and not a substring.
*/

#include <algorithm>
#include <unordered_set>

//太慢了...
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<char> result;
    unordered_set<char> hash_set;
    int max = 0;
    int temp = 0;   //用于确定index
    
    for(int i = 0; i < s.size();i++)
    {
        if(hash_set.count(s[i]))	//有重复的 从重复的后边那个重新计算
        {
            if(max < result.size())
                max = result.size();
            
            //得到重复的那个元素的index 然后下一次循环就从它的下一个元素开始
           // cout << "temp = " << temp;
            i = &*( find(result.begin(),result.end(),s[i]) ) - &result[0] + temp;	//就是这里太慢 没办法用哈希 因为需要求index
         //   cout << "    repeat! then i = " << i << endl;
            //清零
            result.clear();
            hash_set.clear();
            temp = i+1;
            
            
        }
        
        else	//没有重复
        {
            result.push_back(s[i]);
            hash_set.insert(s[i]);
        //    cout << "expand ! i = " << i << endl;
        }
        
        
    }
      if(result.size() > max)
        max = result.size();
    
    return max;
    
    
}

};

//
class Solution {
public:
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
         //   cout <<" length = " << length << endl;
        }
        
        else
        {
            
            while(hash_set.count(s[i]) == 1)//有重复的元素
            {
                hash_set.erase(*result.begin());
                result.erase(result.begin()); //除去第一个元素
                
                // cout << "删除完后 此时result size = " << result.size();
                // cout << "删除完后 此时result begin = " << *result.begin();
                // cout << " s[i] = " << s[i] ;
                // cout << "hash_set.count(s[i]) = " << hash_set.count(s[i]) << endl;
            }
            
            result.push_back(s[i]);
            hash_set.insert(s[i]);
            
        }
        
        if(max < length)
            max = length;
        
    }
    
    return max;
    
}
};