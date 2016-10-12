// 就是有一个string，是由各种路径组成的，比如
//dir
//    ddir1
//        a.jpg
//        ab.gif
//        b.txt
//dir2
//dir3
//    ddir1
//        s.jpg
//    fe.jpg
//    ddir2
//        dddir3
//            s.jpg


// dir\n\tdir1\

// 找到以jpg or gif结尾最长的那个路径，只return 长度。
// 输入: dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext

//dir
//    subdir1
//        file1.ext
//        subsubdir1
//    subdir2
//        subsubdir2
//            file2.ext


//首先要先分解 分解所有\n\t中间的字符串, 如果有.jpg, .gif结尾的就去计算长度 前边有几个\t表示有几层
//然后再去找前边的层数对应的字符串长度, 最后加和. 最后比较


#include <iostream>
#include <string>

using namespace std;

int get_longest_length(string * S);

int main()
{
    string file_system;
	cout << "Input a file system:\n";
	cin >> file_system;
    int num_n = 0;
    int num_path = 0;
   // string *path;
    string test;
    test = file_system.substr(3,2);
    cout << test << endl;
    
    for(int i = 0; i < file_system.length(); i++)
    {
        //get the number of paths we need
        if(file_system.substr(i,2) == "\\n")
            num_n ++;
    }
    
    printf("%d", num_n);
    printf("test\n");

    
    //分解所有\n
    string *path = new string[num_n];
    printf("test2\n");
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
    
    //先求所有路径各有多少个\t
    for(int i = 0; i < num_path; i++)
    {
        for(int n =0;n< path[i].length();n++)
        {
            if(path[i].substr(n,2) == "\\t")
                num_space[i]++;
            
        }
        printf("num_tab[%d] = %d", i, num_space[i]);
    }
    
    
    for(int i = 0; i < num_path; i++)   //遍历所有路径string
    {
        
        if(path[i].find(".ext"))
        {
            length_temp[i] += (path[i].length()-num_space[i]);
            
            //向前边看 遍历前边的所有路径
            for(int k = i;k>=0;k--)
            {
                if(num_space[k] < num_space[i])
                    length_temp[i] += (path[k].length() - num_space[k]);
                
                if(num_space[k] == 0) //到达根目录 路径长度已经加过了
                    break;
                
            }
        }
        
        if(length_temp[i] > length_max)
            length_max = length_temp[i];
        
    }
    
    
    cout << "Length max = " << length_max << endl;
   	return 0;

}

















