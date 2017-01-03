class Solution {
public:
   bool isPalindrome(int x) {
    if(x < 0) //负数一定不是
        return false;
    if(x == 0)
        return true;
    int length = 0;
    int msb;
    
    int temp = x;
    while(x>0) //先确定位数
    {
        x = x/10;
        msb = x%10;
        length++;
    }
    
    cout << " length = " << length << endl;
    
    int i = 0; int j = length-1;
    
    x = temp;
    
    while( (i-j) != 1 && i != j)
    {
    //    cout << "i = " << i << "  x[i] = " <<  ( (x/(int)pow(10,i) ) % 10) << "    ;  j = "<< j <<  "  x[j] = " << ( (x/(int)pow(10,j)) % 10) << endl;
        if( ( ( x/(int)pow(10,i) ) % 10) == ( (x/(int)pow(10,j)) % 10) )
        {
            i++;
            j--;
        }
        else
            return false;
    }
    
    return true;
    
}

};