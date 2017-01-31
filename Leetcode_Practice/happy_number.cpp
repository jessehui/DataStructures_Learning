/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1



*/

class Solution {

unordered_set<int> repeat_num;

public:
    bool isHappy(int n) {
    string s = to_string(n);
    size_t len = s.size();
    int result = 0;
    for(int i=0;i<len;i++)
    {
        result = result + pow((s[i]-'0'),2);
        //      cout << " result  = " << result << endl;
    }
    if(repeat_num.count(result)>0)
        return false;
    
    if(result == 1)
        return true;
    else
    {
        repeat_num.insert(result);
        return isHappy(result);
    }
}
};