class Solution {
public:
    string simplifyPath(string path)
{
    stack<string> s;
    for(int i = 0; i < path.length();)
    {
        //忽略多余的'/'
        while(path[i] == '/')
        {
            i++;
//            cout << " i = " << i << endl;
        }
        if(i >= path.length() )
            break;
        
        //判断'.'和'..'和'...'
        if(path[i] == '.')
        {
            i++;
            if(i >= path.length() )
                break;
            if(path[i] == '.')//是".."
            {
                i++;
                
                

                if(path[i] == '.')  //是"..." 是个文件
                {
                    //s.push(path.substr(i-2,3));
                    int tmp = i;
                    while(i < path.length() && path[i] == '.')
                        i++;
                    if(i >= path.length() || path[i] == '/' )
                        s.push(path.substr(tmp-2,i-tmp+2));
                    
                }
                
                else
                if(s.empty() != true && (path[i] == '/' || i >= path.length()) )//为非空 出栈一个
                    s.pop();
              //  else continue;
            }
            
        }
        
       
        else    //都不是
        {
            int temp = i;   // 起始的位置
            while(i < path.length() && path[i] != '/' )
                i++;
            int temp2 = i;  //最终停的位置
            while(i > 0 && path[temp-1] == '.')
            {
                temp--;
            }
   //         cout << "substr = " << path.substr(temp,temp2-temp) << " ";   //substr(开始的位置, 长度);
            s.push(path.substr(temp, temp2-temp));
        }
        
    }//end for
    
    //把stack中的string拼起来
 //   cout << endl;
    string result = "";
    if(s.empty())
        return "/";
    if(s.top() == "")
        s.pop();
    
    while(s.empty() != true)
    {
   //     cout << "top = " << s.top() << " ";
        result = '/' + s.top() + result;
        s.pop();
//        cout << "result = " << result << endl;
    }
    
    return result;
    
}
};