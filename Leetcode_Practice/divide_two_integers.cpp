#include <climits>
class Solution {
public:             //被除数      除数
   int divide(int dividend, int divisor)
{
    long divd = abs(long(dividend));
    long divs = abs(long(divisor));
    long divs_cp = divs;
    long result;
    
    if(dividend == 0)
        return 0;
    
    if(divisor == 1)
        return dividend;
    
    if(divd < divs)
        return 0;
    
    long long flag1 = 0;
    while(divd > divs)
    {
        divs = divs << 1;   //左移1位 相当于乘2
        flag1 ++;
        if(divd < divs)
            flag1--;
    }
    
  //  cout << "flag1 =" << flag1 << endl;
    long temp = divd - (divs_cp << flag1);    //因为divs本身已经大于divd了, 所以要再除2
    
    flag1 = (long long) 1<<flag1;
   
    int flag2 = 0;
    while(temp > 0)
    {
        temp = temp - divs_cp;
        flag2++;
        if(temp < 0)
            flag2--;
    }
    
 //   cout << "flag2 =" << flag2 << endl;
    result = flag1+flag2;
    if(result > INT_MAX)
        return INT_MAX;
    else
        if(result < INT_MIN)
            return INT_MIN;
    
    if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
        return result;
    
    else return 0-result;
    
    
    
}

};