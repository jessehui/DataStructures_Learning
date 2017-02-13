//Implement pow(x, n).


// Not accepted 291/300
class Solution {
public:
    double myPow(double x, int n) {
        if(x<1 && x > 0 && n > 10000)
            return 0;
        long double result = 1;
        for(int i = 0; i<abs(n); i++)
        {
            if(n>0)
        	{
        	    result *= x;
        	}
        	else
        	{
        	    result /= x;
        	}
        //	cout << result << " ";
        }
        return result;
    }
};



//get idea
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1)
            return 1;
        if(x == -1 && n%2 == 0)
            return 1;
            
        if(n<0 && n>INT_MIN)
        {
            n = -n;
            x = 1/x;
        }
        if(n == INT_MIN)
            return 0;
    	if(n == 0)
    		return 1;
    	if(n == 1)
    		return x;
    	if(n%2==0)
    		return myPow(x*x, n/2);
    	else
    		return x*myPow(x*x, n/2);

    }
};