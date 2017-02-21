/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

*/

//misunderstanding
class Solution {
public:
    string countAndSay(int n) {
        string init = to_string(n);
        while(n>1)
        {
            string result = "";
            string temp = init;
            for(int i = 0; i < temp.size(); )
            {
                char t = temp[i];
                int count = 0;
                while(temp[i] == t)
                {
                    count ++;
                    i++;
                }
                
                result = result + to_string(count) + temp[i-1];
                
                init = result;
            }
            cout << "result = " << result << " ";
            n--;
        }
        return init;
        
    }
};


class Solution {
public:
    string countAndSay(int n) {
        string init = to_string(1);
        while(n>1)
        {
            string result = "";
            string temp = init;
            for(int i = 0; i < temp.size(); )
            {
                char t = temp[i];
                int count = 0;
                while(temp[i] == t)
                {
                    count ++;
                    i++;
                }
                
                result = result + to_string(count) + temp[i-1];
                
                init = result;
            }
            cout << "result = " << result << " ";
            n--;
        }
        return init;
        
    }
};