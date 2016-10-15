//非递归 遍历二叉树的实现

#include <iostream>
#include "stack.h"

using namespace std;

struct treenode{
	int payload;
	treenode *left;
	treenode *right;
	treenode(int value):payload(value), left(nullptr), right(nullptr){}
};





void pre_order(treenode *root)	//先序遍历 打印所有节点payload
{
	stack<treenode*> s;	//stack s 是用来存储treenode*类型的
	treenode* current_node = root;
	while(current_node)
	{
		cout << current_node->payload << " ";	//travel this node
		if(current_node->right)		//先遍历左边, 再遍历右边. 但是因为到左边的leaf后, 很难重新再回到根节点
			s.push(current_node->right);	//所以先把右节点入栈 为了遍历完左边后可以恢复现场遍历右边

		if(current_node->left)
			current_node = current_node->left;	//左边前进
		else{		//分支遍历完了 要从栈中取出过去存放的通向右边的节点
			if(s.empty())	//stack head是否为空
				current_node = nullptr;	//stack head为空, 栈里没有元素, 遍历结束
		
			else{		//如果栈不为空
			current_node = s.top();	//获得栈顶元素
			s.pop();	//清除栈顶元素
			}
		}

	}
}

void level_order(treenode *root)	//use queue BFS
{

}


int main()
{
	treenode *root = new treenode(5);
	root->left = new treenode(3);
	root->right = new treenode(7);
	root->left->right = new treenode(4);

	pre_order(root);
	cout << endl;

	return 0;


}
