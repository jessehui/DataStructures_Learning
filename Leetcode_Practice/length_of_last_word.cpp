/*

Given a string s consists of upper/lower-case alphabets and 
empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

*/


class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> tokens;
        stringstream strstm(s);
        string buf;

        while(strstm >> buf)
        {
        	tokens.push_back(buf);
        }
        
        if(tokens.size() == 0)
            return 0;

        string last = tokens.back();
        for(int i = 0; i<last.size(); i++)
        {
        	if(last[i] < 65 || last[i] > 122)
        	{
        		return 0;
        	}
        	else
        	if(last[i] > 90 && last[i] < 97)
        	{
        		return 0;
        	}

        }
        return last.size();

    }
};




