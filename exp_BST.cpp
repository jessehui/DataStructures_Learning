//using binary search tree to get the result of an expression
//只支持1位数
//e.g. (4+5)*9
/*
	*
     +     9
   4   5
*/

//使用中序遍历可能会有括号和优先级的问题 所以可以使用后序遍历
//即: 45+9*

#include <iostream>
#include <stack>	//标准库的stack
#include <limits>

using namespace std;

struct treenode{
	char payload;
	treenode *left;
	treenode *right;
	treenode(int value) : payload(value), left(nullptr), right(nullptr){}
};

//binary expression tree
class BET{
	treenode *root;

public:
	BET() : root(nullptr){}

	//parse: 解析
	void parse(const char exp[])	//45+9*
	{
		const char *p = exp;
		stack<treenode *> s;	//C++ reference: stack<typename> mystack
		while(*p != '\0')	//字符串最后一个字符永远是'\0'
		{
			if(*p >= '0' && *p <= '9')
			{
                s.push(new treenode(*p));	//如果是数字的话, 就新建一个节点然后入栈
			}

			else	//不是数字 是运算符号
			{
				treenode *new_node = new treenode(*p);
				new_node -> right = s.top();//先分配给右子树 因为栈是先进后出的
				s.pop();	
				new_node -> left = s.top();	//再分配左子树
				s.pop();
				s.push(new_node);	//把新的符号节点入栈
			}

			p++;
		}

		if(s.size() != 1)	//最后应该只剩一个最后的运算符号的节点
		{
			cout << "Illegal";
			root = nullptr;
		}
		else
			root = s.top();
	}

	int evaluate()	//求值
	{
		if(root == nullptr)
			return numeric_limits<int>::max();	//返回int类型的最大的值
		return evaluate(root);
	}

private:
	int evaluate(treenode* node)	//重载
	{
		switch(node->payload)
		{
            case '-': return evaluate(node->left) - evaluate(node->right);
            case '+': return evaluate(node->left) + evaluate(node->right);
            case '*': return evaluate(node->left) * evaluate(node->right);
			default: return node->payload - '0';	//'3' - '0' = 3 char to int


		}

	}


};

int main()
{
	BET bet_test;
	bet_test.parse("25+7*");
	cout << bet_test.evaluate() << endl;
    bet_test.parse("725+*");
    cout << bet_test.evaluate() << endl;
	return 0;
}
















