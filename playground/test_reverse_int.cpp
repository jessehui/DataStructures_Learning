//
//  test_reverse_int.cpp
//  datastucture_test
//
//  Created by Jesse. on 12/30/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <climits>

using namespace std;


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
            cout << "s[j] = " << s[j];
            result = 10 * result + (s[j]-48);
            cout << "   result = " << result << endl;
            if(result-1 > (INT_MAX))
                return INT_MIN;
            
            
        }
        result = 0 - result;
        
        
        
        
    }
    
    else
    {
        for(int j = i;s[j]>47 && s[j]<58; j++)
        {
            cout << "s[j] = " << s[j];
            result = 10 * result +  (s[j]-48);
            cout << "   result = " << result << endl;
            if(result > INT_MAX)
            {
                
                return INT_MAX;
            }
            
        }
    }
    
    check = result;
    return check;
    
}




//    if(s[0] == '+')
//    {
//        cout << "test" << endl;
//        if(length > 1)
//        {
//            for(int i = length-1;i >= 1;i--)
//                result = result + pow(10,(length-i-1)) * (s[i]-48);
//        }
//        else
//            return 0;
//    }
//    
//    else if(s[0] == '-')
//    {
//        for(int i = length-1;i >= 1;i--)
//            result = result + pow(10,(length-i-1)) * (s[i]-48);  //ASCII码值转换为本身的值
//        
//        result = 0-result;
//    }
//    
//    else
//    {
//        cout << "result = " << result;
//    pos:   for(int i = length-1;i >= 0;i--)
//        {
//            cout << "  ;length = " << length << "   ; s[i] = " << s[i] << "  ;power = " << pow(10,(length-i-1));
//            result = result + pow(10,(length-i-1)) * (s[i]-48);
//            cout << "   ;i = " << i << "   ; result = " << result << endl;
//        }
//    }
//    if(result > INT_MAX || result < INT_MIN)
//    {
//        cout << "Oops, over flow" << endl;
//        return 0;
//    }
//    
//    check = result;
//    return check;
//}



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


int main()
{
    string s = "10955020061019238410293480238515921";
    int test = myAtoi(s);
    cout << "test = " << test << endl;
//    int rev = reverse(test);
//    cout << "after reverse = " << rev << endl;
    return 0;
}
