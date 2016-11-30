// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
// P   A   H   N
// A P L S I I G
// Y   I   R






class Solution {
public:
    string convert(string s, int numRows) 
    {
    	string *result = new string(s.size());
    	int n = 0;//n是s的iterator
    	int i = 0;//i是result的iterator
    	int row = 0;




    	while(n <= s.size())
    	{
    		if(row == numRows/2)	//中间那行
    		{
    			result[i] = s[n];
    			n = n + (numRows+1)/2;
    			if(n>s.size())
    			{
    				n = row+1;
    				row++;
    			}
    		}

    		else	//非中间行
    		{
	    		result[i] = s[n];	
	    		n = n+ (numRows+1) + row;
	    		if(n>s.size())
	    		{
	    			n = row+1;
	    			row++;
	    		}
	    	}
	    	
	    	i++;
	    	

    	}
    	return *result;

        
    }
};






