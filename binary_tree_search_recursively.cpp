#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int payload;	//数据
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;	//*Tree表示指向TreeNode这种类型的指针

void Add(TreeNode * root, TreeNode * new_node)
{
	if( (new_node->payload <= root->payload) && (root->left != NULL) )	//如果增加的值小于根节点 且根左边还有节点, 那就递归
		Add(root->left, new_node);
	else if( (new_node->payload <= root->payload) && (root->left == NULL))	//左边为空
		root->left = new_node;
	else if(root->right != NULL)	//大于根节点 右边非空
		Add(root->left, new_node);
	else	//大于根节点 且右边为空
		root->right = new_node;
}

void Pre_Order(TreeNode *root)
{
	if(root)
	{
		printf("%d", root->payload);
		Pre_Order(root->left);
		Pre_Order(root->right);
	}
}

void In_Order(TreeNode *root)
{
	if(root)
	{
		In_Order(root->left);
		printf("%d", root->payload);
		In_Order(root->right);
	}
}

void Post_Order(TreeNode *root)
{
	if(root)
	{
		Post_Order(root->left);
		Post_Order(root->right);
		printf("%d", root->payload);
	}
}


int main()
{
	int num;
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	printf("输入根节点payload: ");
	scanf("%d", &(root->payload));
	root->right = NULL;
	root->left = NULL;
    	printf("输入子节点个数: ");
	scanf("%d", &num);

	
	for(int i = 1;i<num+1;i++)
	{
		printf("输入子节点payload(%d):",i);
		TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
		new_node -> left = NULL;
		new_node -> right = NULL;
		scanf("%d", &(new_node->payload));
		Add(root, new_node);
	}



	//输出遍历结果
	printf("Pre_Order result: \n");
	Pre_Order(root);
	printf("\n");
	printf("In_Order result: \n");
	In_Order(root);
	printf("\n");
	printf("Post_Order result: \n");
	Post_Order(root);
	printf("\n");


}













