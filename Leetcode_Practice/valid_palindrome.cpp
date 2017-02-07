/*
Given a string, determine if it is a palindrome, considering 
only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a
 good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {

private:
	bool isChar(char c)
	{
		if((c>=65 && c<=90) || (c>=97 && c <= 122) || (c>=48 && c<= 57) )
			return true;
		else
			return false;
	}

public:
    bool isPalindrome(string s) {
        if(s.empty())
        	return true;

        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
       //     cout << "loop i, j = " << s[i] << " " << s[j] << "  ";
            
        	if(!isChar(s[i]))
        	{
        		i++;
        // 		cout << "I NO";
        // 		cout << endl;
        		continue;
        	}
        	if(!isChar(s[j]))
        	{
        		j--;
        // 		cout << "J NO";
        // 		cout << endl;
        		continue;
        	}
        	
        	//both is a char
        	if(s[i] == s[j] || (abs(s[i]-s[j]) == 32 && s[i]>57 && s[j]>57)) 
        	{
        		i++;
        		j--;
       // 		cout << endl;
        	}
        	else
        	{
        ///	    cout << "i, j = " << s[i] << " " << s[j] << endl;
        		return false;
        	}
        	
        	

        }
        // cout << "s.size() = " << s.size() << endl;
        // cout << " end i, j = " << i << " " << j << endl;
        // if(i > s.size()/2 || j < s.size()/2)
        //     return false;
        // else
            return true;

    }
};


class Solution {

private:
	bool isChar(char c)
	{
		if((c>=65 && c<=90) || (c>=97 && c <= 122) || (c>=48 && c<= 57) )
			return true;
		else
			return false;
	}

public:
    bool isPalindrome(string s) {
        if(s.empty())
        	return true;

        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
        	if(!isChar(s[i]))
        	{
        		i++;
        		continue;
        	}
        	if(!isChar(s[j]))
        	{
        		j--;
        		continue;
        	}
        	
        	//both is a char
        	if(s[i] == s[j] || (abs(s[i]-s[j]) == 32 && s[i]>57 && s[j]>57)) 
        	{
        		i++;
        		j--;
        	}
        	else
        	{
        		return false;
        	}
	    }
        
        return true;

    }
};
