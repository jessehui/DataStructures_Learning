class Solution {
public:
    int roman(char c)
{
    switch(c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int sum = 0;
    int i=0 ,j = 1;
    while(s[i])
    {
        int left = roman(s[i]);
        int right = roman(s[j]);
        
        if(left<right) //左边的字母小 表示是减去 e.g.IV
            sum = sum - left;
        else
            sum = sum + left;
    
        i++;j++;
        
    //    cout << "i = " << i << "  ; sum = " << sum << endl;
     }
    
    return sum;
}
};