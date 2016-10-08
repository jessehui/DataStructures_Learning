//
//  binary_tree_search_stl.cpp
//  datastucture_test
//  goal: 二叉树遍历实现 利用标准库实现
//  Created by Jesse. on 10/8/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct treenode{
    int payload;
    treenode *left;
    treenode *right;
    treenode(int value) : payload(value), left(nullptr), right(nullptr){}
};

void pre_order(treenode *root)
{
    stack<treenode*> s;
    treenode *current_node = root;
    while(current_node)
    {
        cout << current_node->payload << " ";
        if(current_node->right)
            s.push(current_node->right);
        
        if(current_node->left)
            current_node = current_node->left;
        
        else//分支都遍历完了
        {
            if(s.empty())
                current_node = nullptr; //跳出循环
            else
            {
                current_node = s.top();
                s.pop();
            }
        }
            
        
    
    }
}


int main()
{
    treenode* root = new treenode(5);
    root->left = new treenode(3);
    root->right = new treenode(7);
    root->right->left = new treenode(6);
    
    pre_order(root);
    
    return 0;
}



