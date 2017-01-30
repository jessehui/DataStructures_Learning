class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0)
        	return "E";

        if(numerator == 0)
        	return "0";

        string result;

        if((numerator<0) ^ (denominator<0))	//相异为真
        	result += "-";

        long num = abs(long(numerator));
        long deno = abs(long(denominator));

        result += to_string(num/deno);	//get the integral part
        
        if(num%deno == 0)
        	return result;

        result += ".";
        unordered_map<int, int> map;	//<rem, position in the string>
        for(long rem = num%deno; rem!=0 ; rem = rem%deno)
        {
        	if(map.count(rem)>0)    //只有相同的余数才会存储
        	{
        		result.insert(map[rem],"(");
        		result = result+")";
        		break;

        	}

        	map[rem] = result.size();	//position = length
        	rem = rem*10;
        	result = result+ to_string(rem/deno);
        }

        return result;


    }
};