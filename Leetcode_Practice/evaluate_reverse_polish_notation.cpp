/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i<tokens.size(); i++)
        {
        	if(tokens[i][0] >= 48 && tokens[i][0] <= 57)
			{
				s.push(stoi(tokens[i]));
			}
			else if(tokens[i].size()>1)  //-4 , +6
			{
			    if(tokens[i][0] == '-' || tokens[i][0] == '+')
			    {
			        s.push(stoi(tokens[i]));
			    }
			}
			
			else
			{
				int temp2 = s.top();
				s.pop();
				int temp1 = s.top();
				s.pop();
				switch(tokens[i][0])
				{
					case '+': {s.push(temp1+temp2); continue;}
					case '-': {s.push(temp1-temp2); continue;}
					case '*': {s.push(temp1*temp2); continue;}
					case '/': {s.push(temp1/temp2); continue;}
				}
			}
        }

        return s.top();
    }
};


