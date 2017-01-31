/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another 
character while preserving the order of characters. No two characters may 
map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true. 
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s == t)
        	return true;
        int pos;
        unordered_map<char, int> char_pos;
        unordered_map<int,vector<int>> map;	//<first position, all position>
        unordered_map<int,vector<int>> map2;	//<first position, all position>
        for(int i = 0; i< s.size(); i++)	//find the relation
        {
        	if(char_pos.count(s[i])>0)
        	{
        		pos = char_pos[s[i]];
        		map[pos].push_back(i);
        	}
        	else
        	{
        		char_pos[s[i]] = i;
        		map[i].push_back(i);
        	}
        }

        char_pos.clear();

        for(int i = 0; i< t.size(); i++)	//find the relation
        {
        	if(char_pos.count(t[i])>0)
        	{
        		pos = char_pos[t[i]];
        		map2[pos].push_back(i);
        	}
        	else
        	{
        		char_pos[t[i]] = i;
        		map2[i].push_back(i);
        	}
        }

        for(int i = 0; i<t.size();i++)
        {
        	if(map[i] != map2[i])
        		return false;
        }

        return true;


        //can't do this. if the first one is different and the second is the same, there is a bug
        //e.g. ab & aa
        // //check the other string
        // for(int i = 0; i<t.size();i++)
        // {
        // 	for(int j = 0; j<map[i].size(); j++)	//traverse the vector
        // 	{
        // 		if(t[map[i][0]] != t[map[i][j]])
        // 			return false;
        // 		else
        // 			continue;
        // 	}
        // }
        //return true;

    }
};