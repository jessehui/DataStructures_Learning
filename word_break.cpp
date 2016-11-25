//给定一个字符串, 在给一个字典, 把这个字符串拆分成多个词
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>	//hash set (count函数:存在的个数)

using namespace std;


void print_result(vector<string> &result, int length)
{
	if(length == 0)
		return;
	string word = result[length];
	print_result(result,length-word.length());
	cout << " " << word;
}


void word_break(unordered_set<string> &dict, string str)
{
	vector<string> result;
	result.resize(str.length() + 1, "");//string全部初始化为空
	//+1是因为存在word_length为0的时候

	for(int i = 0; i<=str.length();i++)
	{
		//把所有包含完整词语的string挑出来存到result里(比如word, wordb,wordbre,..., wordbreak等)
		string word = str.substr(0,i);
		if(dict.count(word) > 0)
		{
			result[i] = word;
			continue;
		}

		//对可能有词语组合的string再拆分
		for(int j = 0;j<i;j++)
		{
			//前边不能是空字符串(为空表示不在字典中)
			if(result[j] != "")
			{
				//比如说现在到wordbre了, i是7, i-j是length
				string word = str.substr(j,i-j);
				if(dict.count(word) > 0)
					{result[i] = word;break;}
			}
		}

	}
	if(result[str.length()] != "")
	{
		print_result(result, str.length());
	}
}






int main()
{
	unordered_set<string> dict = {
		"word", "ord", "break", "problem", "lem", "pro",
		"db","wor"
	};

	word_break(dict, "wordbreakproblem");
}