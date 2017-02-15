/*
A message containing letters from A-Z is being encoded to numbers
 using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the 
total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

unordered_maps<char, int> char_int;
for(int i = 0 ; i< 26; i++)
{
	char_int['A'+i] = i+1;
}


// 233/269 
class Solution {
public:
    
    
    
    int numDecodings(string s) {
        if(s.size()<1 || s[0] == '0' || (*(s.end()-1) == '0' && (*(s.end()-2) - '0') >= 3 ) )
            return 0;
        int result = 0;
        vector<int> ways(s.size(),0);
        ways[0] = 1;	//one number must correspond to a character
        
        for(int i = 0; i< s.size()-1; i++)
        {
            if( s[i+1] == '0' && ( (s[i] == '0')||(s[i]-'0' >= 3) )   )
        	        return 0;
            int temp = stoi(s.substr(i,2));
            
            if(i>=1 && s[i+1] == '0' && s[i]-'0' < 3)
            {
        //        cout << "带0 可以继续 "<<endl;
                ways[i+1] = ways[i-1];
            }
        	else if(i>0 && s[i]!= '0' && temp <= 26 && temp > 0)
        	{
        //	    cout << "正常" << endl;
        		ways[i+1] = ways[i]+ways[i-1];
        	}
        	else if(i==0 && s[i+1] != '0' &&  temp <= 26)
        	{
    //    	    cout << "计算第1个元素" << endl;
        	    ways[i+1] = ways[i]+1;
        	}
        	else
        	{
       // 	    cout << "其他情况" << endl;
        		ways[i+1] = ways[i];
        	}
        	
        // 	if(i>0 && s[i+1] == '0')
        // 	    ways[i+1] -= 1;
        	
     //   	cout<<"ways"<<"["<<i+1<<"]"<< " = " << ways[i+1] << endl;
        }
        
        return ways.back();

    }
};


