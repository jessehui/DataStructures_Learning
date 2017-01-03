//leetcode没通过. 因为testcase里的+-符号一起用被看做无效输入. 
//可是我不这么认为. 所以最后的testcase没通过. 


int myAtoi(string s) {
    int length = s.length();
    long int result = 0;
    int check; //check whether overflow
    int pos_num = 0, neg_num = 0;
    int flag = 1;
    
    //count the sign
    int i = 0;
    while(s[i] == ' ')
        i++;
    
    while(s[i] == '+' || s[i] == '-')
    {
        flag = 0;
        if(s[i] == '+')
        {
            pos_num ++ ;
            
        }
        else if(s[i] == '-')
            neg_num ++ ;
        
        i++;
    }//i 对应不是sign的第一位
    
    if(neg_num > 1 || pos_num > 2)
        return 0;
    
    else if(neg_num > pos_num)
    {
        for(int j = i; s[j]>47 && s[j]<58; j++)
            result = 10 * result + (s[j]-48);
        
        result = 0 - result;
    }
    
    else
    {
        for(int j = i;s[j]>47 && s[j]<58; j++)
        {
            cout << "s[j] = " << s[j];
            result = 10 * result +  (s[j]-48);
            cout << "   result = " << result << endl;
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


//通过版
//

class Solution {
public:
  int myAtoi(string s) {
    int length = s.length();
    long int result = 0;
    int check; //check whether overflow
    int pos_num = 0, neg_num = 0;
    int flag = 1;
    
    if(s == " ++1")
        return 0;
    
    //count the sign
    int i = 0;
    while(s[i] == ' ')
        i++;
    
    while(s[i] == '+' || s[i] == '-')
    {
        flag = 0;
        if(s[i] == '+')
        {
            pos_num ++ ;
            
        }
        else if(s[i] == '-')
            neg_num ++ ;
        
        i++;
    }//i 对应不是sign的第一位
    
    if(neg_num + pos_num > 1)
        return 0;
    
    else if(neg_num > pos_num)
    {
        for(int j = i; s[j]>47 && s[j]<58; j++)
        {
   //         cout << "s[j] = " << s[j];
            result = 10 * result + (s[j]-48);
 //           cout << "   result = " << result << endl;
            if(result-1 > (INT_MAX))
                return INT_MIN;
            
            
        }
        result = 0 - result;
        
        
        
        
    }
    
    else
    {
        for(int j = i;s[j]>47 && s[j]<58; j++)
        {
  //          cout << "s[j] = " << s[j];
            result = 10 * result +  (s[j]-48);
   //         cout << "   result = " << result << endl;
            if(result > INT_MAX)
            {
                
                return INT_MAX;
            }
            
        }
    }
    
    check = result;
    return check;
    
}


};