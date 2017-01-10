class Solution {
public:
    bool isValid(string s) {
   
    size_t length = s.length();
    if(length == 0)
        return true;
    
    vector<char> stack;
    
    for(int i = 0;i < length; i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            stack.push_back(s[i]);
        }
        
        else
            if(stack.size() != 0 && stack.back() == '{' && s[i] == '}')
            {
                cout << "stack.back() =" << stack.back();
                stack.pop_back();
            }
        else
            if(stack.size() != 0 && stack.back() == '[' && s[i] == ']')
                stack.pop_back();
        else
            if(stack.size() != 0 && stack.back() == '(' && s[i] == ')')
                stack.pop_back();
        
        else return false;
    }
    
    cout << "Final size = " << stack.size() << endl;
    
    
    if(stack.size() == 0)
        return true;
    else return false;
    
}

};