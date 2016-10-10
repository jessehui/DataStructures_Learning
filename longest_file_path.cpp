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
// 输入: dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext\n



//首先要先分解 分解所有\n\t中间的字符串, 如果有.jpg, .gif结尾的就去计算长度 前边有几个\t表示有几层
//然后再去找前边的层数对应的字符串长度, 最后加和. 最后比较


#include <iostream>
#include <string>

using namespace std;

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
        //看需要多少个字符串来存放分解的路径
        if(file_system.substr(i,2) == "\\n")
            num_n ++;
    }
    
    printf("%d", num_n);
    
    //分解所有\n \t
    string *path = new string[num_n];
    for(int i = 0; i < file_system.length(); i++)	//
    {
    	for(int j = 0; j < file_system.length(); j++)
    	{
    	    if(file_system.substr(j,2) == "\\n" || file_system.substr(j,2) == "\\t" )
	    {
	        path[num_path] = file_system.substr(i,j-i);
            cout << path[num_path];
            num_path++;
	    }
	}
    }
    
   	return 0;

}
















