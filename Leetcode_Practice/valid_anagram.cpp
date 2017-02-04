/*Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/


//anagram: 相同字母异序词，易位构词，变位词



class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.size() != t.size())
    		return false;

        unordered_map<char, int> char_num;
        for(int i = 0; i< s.size(); i++)
        {
        	char_num[s[i]]++;
        }

        for(int i = 0; i<t.size(); i++)
        {
        	if(!char_num.count(t[i]))	//if not exist
        		return false;

        	char_num[t[i]]--;
        }

        for(auto it = char_num.begin(); it != char_num.end(); it++)
        {
        	if(it->second != 0)
        		return false;
        }

        return true;
    }
};



