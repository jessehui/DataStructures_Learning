//
//  test_binary_tree.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/10/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int payload;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int payload): payload(payload), left(nullptr), right(nullptr){};
};

void Add(TreeNode *root, TreeNode *new_node)//recursively
{
    if(new_node->payload <= root->payload && root->left != nullptr )//新节点小于根节点 但是根节点左侧节点不为空
        Add(root->left, new_node);
    else if(new_node->payload <= root->payload && root->left == nullptr)
        root->left = new_node;
    else    //新节点大于根节点
        if(root->right != nullptr )
            Add(root->right, new_node);
    else
        root->right = new_node;
    
}

void pre_order(TreeNode *root)  //先打根节点
{
    int i = 0;
    if(root != nullptr)
    {
        printf("level = %d  ;  ",++i);
        printf("%d\n", root->payload);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(TreeNode *root)   //先打最小的值的节点 in order表示按顺序
{
    if(root)
    {
        in_order(root->left);
        printf("%d", root->payload);
        in_order(root->right);
    }
}

void post_order(TreeNode *root)// 最后打印根节点
{
    if(root)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d", root->payload);
    }
}


//non-recursively
void pre_order2(TreeNode *root)
{
    stack<TreeNode*> s; //用于存储TreeNode地址
    TreeNode *current = root;   //不改变root的地址
    
    while(current)  //current node为非空
    {
        //pre-order 先打印根节点
        printf("%d", current->payload);
        
        //先把右边节点入栈
        if(current->right != nullptr)
        {
            s.push(current->right);
        }
        
        //遍历左边
        if(current->left != nullptr)
        {
            current = current->left;
        }
        
        else    //左边为空 开始右边
        {
            if( s.empty() ) //tree遍历完毕
                current = nullptr;
            
            else    //开始遍历右边
            {
                current = s.top();
                s.pop();
            }
        }
    }
}


void pre_order3(TreeNode *root)
{
    stack<TreeNode*> s;
    TreeNode *current = root;
    while(current != nullptr)
    {
        cout << current->payload << " ";
        
        if(current->right)
        {
            s.push(current->right);
        }
        
        if(current->left)
        {
            current = current->left;
        }
        
        else
        {
            if(s.empty())
            {
                current = nullptr;
            }
            
            else
            {
                current = s.top();
                s.pop();
            }
            
        }
        
    }
}


//void in_order_test(TreeNode *root)
//{
//    TreeNode *current = root;
//    stack<TreeNode *> s;
//    
//    while(current)
//    {
//        //先入栈中间节点 只要不是叶节点
//        if(current->left != nullptr || current->right != nullptr)
//            s. push(current);
//        
//        //向最下边去
//        if(current->left)
//        {
//            current = current -> left;
//        }
//        
//        else
//        {
//            if(s.empty())
//            if(current->left == nullptr)
//            {
//                cout << current->payload << " ";
//                current = s.top();
//                s.pop();
//                cout << current->payload << " ";
//            }
//        }
//        
//    }
//    
//}

void in_order2(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* current = root;
    
    while(current!= nullptr || s.empty() != true)
    {
        //先去到左子树最底层
        while(current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        
        //此时current为空 所以pop一个
        if(s.empty() != true)
        {
            current = s.top();
            cout << current -> payload << " ";
            s.pop();
            current = current -> right; //如果是空的话 下一轮循环直接会再pop一个
        }
        
    }
}

void in_order3(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *current = root;
    
    while(current!=nullptr || s.empty() != true)
    {
        //先把左边所有节点入栈
        while(current)
        {
            s.push(current);
            current = current->left;
        }
        
        //current现在对应为空, 所以先pop一个
        if(!s.empty())
        {
            current = s.top();
            s.pop();
            cout << current->payload << " ";
            current = current->right;
        }
        
    }
    
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(12);
    root->left->right = new TreeNode(7);
    root->left->left  = new TreeNode(3);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(8);
    root->right->left = new TreeNode(11);
    root->right->left->left = new TreeNode(9);
    root->right->left->right = new TreeNode(13);
    root->right->right = new TreeNode(15);
    
    
    //cout << "Node 4 left: " << root->left->right->left->payload << endl;
    in_order(root);
    cout << endl;
    in_order3(root);
    cout << endl;
    
    return 0;
    
    
}
