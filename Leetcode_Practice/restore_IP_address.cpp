/*
Given a string containing only digits, restore it by returning 
all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

*/

//mess
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string group;	//255.255.11.135
        string set;		//255/11/135		must smaller than 255 to be valid
        backtracking(s, set, group, result,)
        return result;
    }


private:															 //valid IP address should have 4 sets
	void backtracking(string& s, string& set, string& group, vector<string>& result, int set_n, int index)    
	{
		if(set_n == 4)
		{
			group.erase(group.end()-1);	// erase the last '.'
			result.push_back(group);
			return;
		}

		if(set.size() == 3)
		{
			set += '.';
			group += set;
			set_n++;
			return;
		}



		for(int i = index; i<s.size(); i++)
		{
			set += s[i];
			backtracking(s, set, group, result, set_n, i);
		}
	}
};




class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string temp;

        for(int a = 1; a<= 3; a++)
        	for(int b = 1; b <= 3; b++)
        		for(int c = 1; c <= 3; c++)
        			for(int d = 1; d <= 3; d++)
        			{
        				if(a+b+c+d == s.size())
        				{
        					int A = stoi(s.substr(0,a));
        					int B = stoi(s.substr(0+a, b));
        					int C = stoi(s.substr(0+a+b, c));
        					int D = stoi(s.substr(0+a+b+c, d));

        					if(A <= 255 && B <= 255 && C <= 255 && D <= 255)
        					{
        						temp = to_string(A) + '.' +  to_string(B) + '.' + to_string(C) + '.' + to_string(D);
        						if(temp.size() == s.size()+3)
            					{
            						result.push_back(temp);
            				    	temp.clear();
            					}
            					else
            					    temp.clear();
        					}
        					
        				}
        			}
        			
        return result;
    }
};
















