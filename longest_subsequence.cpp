/*Let X be “XMJYAUZ” and  Y be “MZJAWXU”. 
The longest common subsequence between X and Y is “MJAU”.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int lcs_recursive(char a[], int a_length, char b[], int b_length)
{	
	//测试递归次数
	static int count = 0;
	cout << ++count << endl;

	if(a_length == 0 || b_length == 0)
		return 0;
	else if(a[a_length - 1] == b[b_length - 1])	//最后一位一样 就缩减长度
		return 1 + lcs_recursive(a, a_length-1, b, b_length - 1);
	else{//最后一位不一样, 那么可能a的最后一位在最长子序列, 也可能b的最后一位在最长子序列
		//a的最后一位在最长子序列
		int a_has_l = lcs_recursive(a, a_length, b, b_length-1);
		int b_has_l = lcs_recursive(a, a_length-1, b, b_length);
		return max(a_has_l, b_has_l);
	}

}

/*
形成一个table查表 横的是一个字符串, 竖的是另一个字符串
	    0	    a	    b	    e
-------------------------------------
 0   |	0	    0	    0	    0
 a   |  0	    1	    1(a和ab)1(a,abe)
 b   |	0       1(ab,a) 2(ab,ab)2(ab,abe)
 c   |	0	    1(abc,a)2(abc,ab)2(abc,abe)

*/
int lcs_dp(char a[], int a_length, char b[], int b_length)
{
	vector<vector<int>> value_table;
    //void resize (size_type n, value_type val = value_type());
	value_table.resize(a_length + 1, vector<int>(b_length + 1, 0));//因为有0
    
    for(int i = 0; i <= a_length; i++)
        for(int j = 0; j <= b_length; j++)
        {
            if(i == 0 || j == 0)
                value_table[i][j] = 0;
            else if(a[i] == b[j])
                value_table[i][j] = value_table[i-1][j-1] + 1;
            else
                value_table[i][j] = std::max(value_table[i-1][j], value_table[i][j-1]);
        }
    //index 从 0 ~ length 共 length+1个元素
    return value_table[a_length][b_length];   //就是最右下角的元素
    
	
}



int main()
{
	char a[] = "ABCDGH";
	char b[] = "AEDFHR";
	cout << lcs_recursive(a, 6, b, 6) << endl;
    cout << endl;
    cout << lcs_dp(a,6,b,6) << endl;
	return 0;
}


