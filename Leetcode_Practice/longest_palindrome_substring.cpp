// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example:

// Input: "babad"

// Output: "bab"

// Note: "aba" is also a valid answer.
// Example:

// Input: "cbbd"

// Output: "bb"


//method 1: expand around center
class Solution {
public:
int expand_palindrome(string s, int left, int right)
{
    while(left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--;
        right++;
    }
    // cout << "left = " << left << "   ; right = " << right;
    // cout << "   palin length =  " << right-1-(left+1)+1 << endl;
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
       // cout << "最大的回文中心是: " << index << "  ; max_ = " << max_ << "  ; final flag = " << final_  << endl;
    }
    
    return s.substr(index-max_/2+final_, max_);
}




};



//method 2: 
// Reverse SS and become S'S
// ​′
// ​​ . Find the longest common substring between S and S'
// ​
// ​​ , which must also be the longest palindromic substring.

class Solution {
public:
    string longestPalindrome(string s) 
    {
    	string s_prime = s;
    	reverse(s_prime.begin(),s_prime.end());
    	cout << "after reverse :" 
    	for(string::iterator it = s_prime.begin();it != s_prime.end(); ++it)
    		cout << *it << " ";
    	cout << endl;
    	vector<char> temp;
    	int num = 0;

    	//find the common string
    	for(string::iterator it_s = s.begin(); it_s != s.end(); ++it_s)
    		for(string::iterator it_sp = s_prime.begin(); it_sp != s_prime.end(); ++it_sp)
    		{
    			while(*it_s == *it_sp)
    			{
    				temp.push_back(*it_s);
    				it_s++; it_sp++;
    				
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
    	string return_ = temp;
    	return return_;

        
    }
};