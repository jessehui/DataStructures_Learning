//给定一个字典,替换某个词语的某一个字母, 生成一个新的词语
//不断替换替换, 直到成为目标词语


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>	//未排序的树 其实就是hash_map
#include <queue>


using namespace std;

struct word_node{
	string word;
	bool visited;
	string previous;
	word_node(string word): word(word),visited(false),previous(""){}
};


//print path
void print_result(unordered_map < string, word_node* > &word_map, word_node *node)
{
	if(node->previous != "")
	{
		print_result(word_map, word_map[node->previos])	
	}
	cout << "->" << node->word;
}

//words: 词库(dic) 
void word_ladder(vector<string> &words, string start, string end)
{
	unordered_map<string, word_node*> word_map;

	//init 
	for(int i = 0; i < words.size(); i++)
	{
		word_node *node = new word_node(words[i]);	//对词库里的每一个词都新建一个word_node
		word_map[words[i]] = node;	//建立hashmap, words[i]就是key, 对应的hash值就是新建的node
	}

	queue<word_node *> q;
	word_map[start]->visited = true;
	q.push(word_map[start]);

	while(!q.empty())	//广度优先(BFS) 用queue
	{
		word_node* current_node = q.front();
		q.pop();
		for(int i = 0; i < current_node->word.length();i++)//every char in the first word
		{
			for(char c = 'a'; c <= 'z'; c++)
			{
				string str_word = current_node -> word;
				str_word[i] = c;
				if(str_word == end)	//已经到目标了
				{
					print_result();
					cout << "->" << end << endl;
					return;	//直接跳出函数
				}

				//word在字典中存在且没有被访问过
				if(word_map.count(str_word) && word_map[str_word]->visited == false)
				{
					word_map[str_word]->visited = true;
					word_map[str_word]->previous = current_node->word;
					cout << "visiting " << str_word << "from" << current_node->word << endl;
					q.push(word_map[str_word]);
				}

			}

		}
	}

}





int main()
{
	vector<string> dictionary = {"hot","dot","hit", "dog","lot","log", "cog"};
	string start = "hit";
	string stop  = "cog";
	word_ladder(words, start, end);
	return 0;
}


