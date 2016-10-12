// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//I don't understand what the input string will be looked like
//I assume the string consists of a lot of \n and spaces to look like a file system

int solution(string &file_system) {
    // write your code in C++11 (g++ 4.8.2)
    int num_n = 0;  //number of /n
    int num_path = 0;
    
    for(int i = 0; i < file_system.length(); i++)
    {
        //get the number \n 
        if(file_system.substr(i,2) == "\\n")
            num_n ++;
    }
    num_n++;    //add the root dir
    printf("%d", num_n);
    printf("test\n");
    
    // split all the path for each dir or file
    string *path = new string[num_n];
    int front_index = 0;
    for(int j = 0; j < file_system.length(); j++)
    {
        if(file_system.substr(j,2) == "\\n"  )
        {

            path[num_path] = file_system.substr(front_index,j-front_index);
            cout << path[num_path] << endl;
            num_path++;
            while(file_system.substr(j,2) == "\\n" )
            {
                j+=2;
            }
            front_index = j;
        }
    }
    
    int length_max = 0;
    int num_space[num_path];
    for(int i =0;i<num_path;i++)
        num_space[i] = 0;
    int length_temp[num_path];
    for(int i =0;i<num_path;i++)
        length_temp[i] = 0;
        
    //calculate the number of space for each path
    for(int i = 0; i < num_path; i++)
    {
        for(int n =0;n< path[i].length();n++)
        {
            if(path[i].substr(n,2) == " ")
                num_space[i]++;
            
        }
    }
    
    for(int i = 0; i < num_path; i++)   //traverse all path string
    {
        
        if(path[i].find(".jpeg") || path[i].find(".png") || path[i].find(".gif"))   //if has these types of files
        {
            length_temp[i] += (path[i].length()-num_space[i]);
            
            //look ahead of all the path string before and add the length with less spaces
            for(int k = i;k>=0;k--)
            {
                if(num_space[k] < num_space[i])
                    length_temp[i] += (path[k].length() - num_space[k]);
                
                if(num_space[k] == 0) //until reach the root dir
                    break;
                
            }
        }
        
        if(length_temp[i] > length_max)
            length_max = length_temp[i];
        
    }
    

    return length_max;


}