//为什么能用rolling hash:
//abcdef字符串中abcd的hash值: (((31*a)+b)*31+c)*31+d
//也就等于: 31^(4-1)*a + 31^(4-2)*b + 31^(4-3)*c +d
//所以每次计算新的hash值,就把最前边的项减掉, 再乘以31, 再加上最新的一项就是新的hash值

#include <iostream>

using namespace std;

const unsigned PRIME_BASE = 31;

//&表示引用 加const表示这些参数的值不能在函数中被修改
int find_sub_str(const string& source, const string& pattern)
{
	unsigned source_hash = 0, pattern_hash = 0;
	unsigned power = 1;
	size_t pattern_length = pattern.length();

	//先求pattern的hash值, 然后看source前pattern_length的哈希值
	for(int i = 0; i < pattern.length(); i++)
	{
		pattern_hash = pattern_hash * PRIME_BASE + pattern[i];
		source_hash = source_hash * PRIME_BASE + source[i];
		power *= PRIME_BASE;	// for rolling. 因为rolling要减去最高的一项, 加上最新的一项
	}

	//哈希值相等 也要逐个看一下是否每个字符真的相等
	//先检查初始的情况
	if(pattern_hash == source_hash && pattern == source.substr(0,pattern_length))
		return 0;	
	for(int i = pattern_length; i < source.length(); i++)
	{
		//这里先乘,加 后减, 减的时候就不是power-1了,就是power了
		source_hash = source_hash * PRIME_BASE + source[i];
		source_hash = source_hash - power * source[i-pattern.length()];	
	
		if( pattern_hash == source_hash && pattern == source.substr(i-(pattern_length-1),pattern_length) )
			return i-(pattern_length-1);
	}

	//遍历完了都没有
	return -1;	
}

int main()
{
	cout << find_sub_str("cadabbbcccddd", "cd")<<endl;
	return 0;
}
