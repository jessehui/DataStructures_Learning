class Solution {
public:
    string intToRoman(int num)
{
    string M[] = {"", "M", "MM", "MMM"}; //0-3000
    string C[] = {"", "C", "CC", "CCC", "CD", "D","DC","DCC","DCCC","CM"};   //0-900
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX","LXXX","XC"};    //0-90
    string I[] = {"", "I", "II","III","IV","V","VI","VII","VIII","IX"};     //0-9
    
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[(num%10)];
    
    
}
};