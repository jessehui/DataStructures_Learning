// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

//spoilers: 
//If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. 

class Solution {
public:
int str2int(string &s)
{
    int length = s.length();
    long int result = 0;
    int check; //check whether overflow
    
    if(s[0] == '-')
    {
        for(int i = length-1;i >= 1;i--)
            result = result + pow(10,(length-i-1)) * (s[i]-48);  //ASCII码值转换为本身的值
        
        result = 0-result;
    }
    
    else
    {
        cout << "result = " << result;
        for(int i = length-1;i >= 0;i--)
        {
            cout << "  ;length = " << length << "   ; s[i] = " << s[i] << "  ;power = " << pow(10,(length-i-1));
            result = result + pow(10,(length-i-1)) * (s[i]-48);
            cout << "   ;i = " << i << "   ; result = " << result << endl;
        }
    }
    if(result > INT_MAX || result < INT_MIN)
    {
        cout << "Oops, over flow" << endl;
        return 0;
    }
    
    check = result;
    return check;
}

int reverse(int x) {
    // char temp[32];	//设int最大长度为32位
    // char new_temp[32];
    // sprintf(temp, "%d", x);	//数字转换成char
    // printf("temp[0] = %c", temp[0]);	//test
    
    if(x == 0)
        return 0;
    
    string temp = to_string(x);
    cout << "string int = " << temp << endl;
    int result;
    int flag = 0;
    
    
    int i = temp.size() - 1;
    while(temp[i] == '0')
        i--;

    string new_temp(i+1,0); //初始大小为i+1, 值都为0的string
    if(temp[0] == '-')
    {
        new_temp[0] = '-';
        flag = 1;	//负
    }
    
    
    cout << "减完0 到第i = " << i <<endl;
    for(int j = flag; i>=flag ;j++)
    {
        new_temp[j] = temp[i];
        i--;
    }
    cout << "new temp = " << new_temp << endl;
    result = str2int(new_temp);
    return result;
}

};



//another solution 
//very short: use *10 and %10 the same time
public int reverse(int x) {
        long rev= 0;
        while( x != 0){
            rev= rev*10 + x % 10;
            x= x/10;
            if( rev > Integer.MAX_VALUE || rev < Integer.MIN_VALUE)
                return 0;
        }
        return (int) rev;
    }

    