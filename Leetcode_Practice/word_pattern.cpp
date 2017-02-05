/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection 
between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, 
and str contains lowercase letters separated by a single space.

*/


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if((str.find_last_of(" ") == string::npos && pattern.size()!=1))
            return false;
        
    	vector<string> words;
    	//boost::split(words, str, boost::is_any_of(" "));
    	stringstream iss(str);
    	string buff;    //buffer string
    	while(iss>>buff)
    	{
    	    words.push_back(buff);
    	}
    	if(words.size() != pattern.size())
    	    return false;
    	    
    	unordered_map<char, string> char_str;

    	for(int i = 0 ; i< pattern.size();i++)
    	{
    		if(char_str.count(pattern[i]))
    		{
    			if(char_str[pattern[i]] != words[i])
    				return false;
    		}
    		else
    		{
    			char_str[pattern[i]] = words[i];
    			if(find(words.begin(),words.begin()+i, words[i]) != words.begin()+i )   //repeat before
    			    return false;
    		}
    	}

    	return true;
    }
};
