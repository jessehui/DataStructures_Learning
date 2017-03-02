/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

class Solution {
public:
    string addBinary(string a, string b) {
        int size_a = a.size();
        int size_b = b.size();
        int length;
        //int diff = (size_a > size_b ? size_a - size_b : size_b - size_a);
        int diff;
        if(size_a > size_b)
        {
        	diff = size_a - size_b;
        	b.insert(0,diff,'0');
        }
        else if(size_a < size_b)
        {
        	diff = size_b - size_a;
        	a.insert(0, diff, '0');
        }
        length = a.size();
        string temp(length,'0');
        int flag = 0;
        for(int i = length-1; i >= 0; i--)
        {
        	if(a[i] == '1' && b[i] == '1')
        	{
        		if(flag == 0)
        		{
	        		flag = 1;
	        		temp[i] = '0';
	        	}
	        	else	//flag == 1
	        	{
	        //		flag = 1;
	        		temp[i] = '1';
	        	}
        	}

        	else if(a[i] == '0' && b[i] == '0')
        	{
        		if(flag == 1)
        		{
        			flag = 0;
        			temp[i] = '1';
        		}
        		else
        		{
        			temp[i] = '0';
        		}
        	}

        	else
        	{
        		if(flag == 1)
        		{
        			temp[i] = '0';
        		}
        		else	//flag == 0
        		{
        			temp[i] = '1';
        		}
        	}
        	
  //      	cout << "temp = " << temp << endl;
        }

        if(flag == 1)
        	temp.insert(0,1,'1');

        return temp;

    }
};