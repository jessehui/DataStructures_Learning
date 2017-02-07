/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

//idea: 
//Start from right to left, perform multiplication on every pair of digits, 
//and add them together. Let's draw the process! From the following draft, 
//we can immediately conclude:

// `num1[i] * num2[j]` will be placed at indices [i + j, i + j + 1] 


inline int ch2int(char c)
{
	return int(c - '0');
}

inline char int2ch(int i)
{
	return char('0'+i);
}

class Solution {
public:
    string multiply(string num1, string num2) {
    	vector<int> result(num1.size()+num2.size(),0);
        for(int i = num1.size()-1; i >= 0; i--)
        {
        	for(int j = num2.size()-1; j >= 0; j--)
        	{
        		int temp = ch2int(num1[i]) * ch2int(num2[j]);
        		result[i+j+1] = result[i+j+1]+ (temp%10);
        		if(result[i+j+1] >= 10)
        		{
        			result[i+j]++;
        			result[i+j+1] -= 10;
        		}
        		result[i+j] = result[i+j] + (temp/10);
        		if(result[i+j] >= 10)
        		{
        			result[i+j-1]++;
        			result[i+j] = result[i+j] - 10;
        		}

        // 		for(auto it = result.begin(); it != result.end(); it++)
        // 		{
        // 			cout << *it << " ";
        // 		}
        // 		cout << endl;
        	}
        }

        string res_str = "";
        for(int i = 0; i < result.size(); i++)	
        {
        	if(i == 0 && result[i] == 0)
        		continue;
        	res_str += int2ch(result[i]);
        }
        
 //       cout << "res_str  = " << res_str << endl;
    
        if(res_str[0] == '0') //如果最高位是0的情况已经减掉了, 如果这个时候最高位还是0, 那就只能全都是0
             return "0";

        return res_str;


    }
};



