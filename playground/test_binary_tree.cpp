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
#include <queue>

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

void post_order2(TreeNode *root)// 最后打印根节点
{
    if(root)
    {
        post_order2(root->left);
        post_order2(root->right);
        printf("%d  ", root->payload);
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

void level_order(TreeNode *root)
{
    queue<TreeNode *> q;
    TreeNode *current = root;
    q.push(current);
    
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        
        cout << current -> payload << " ";
        
        if(current->left)
        {
            q.push(current->left);
        }
        
        if(current->right)
        {
            q.push(current->right);
        }
    }
    
}

void zigzag_order_test(TreeNode * root) //不行 没办法只用队列做
{
    queue<TreeNode*> q;
    TreeNode* current = root;
    int flag = 1;   //1,3,5...行 flag-1; 2,4,6....行 flag-0;
    
    //先把根节点入列
    q.push(current);
    flag = 0;
    while(!q.empty())
    {
        //取出最前边的元素
        current = q.front();
        q.pop();
        cout << current->payload << " ";
        
        //入栈下一层的元素
        if(flag == 0)   //偶数 先入右边的 后入左边的
        {
            flag = 1;
            if(current->right)
                q.push(current->right);
            
            if(current->left)
                q.push(current->left);
        }
        
        else//flag = 1 奇数行 先入左边, 后入右边
        {
            flag = 0;
            if(current->left)
                q.push(current->left);
            
            if(current->right)
                q.push(current->right);
        }
    }
}

//两个stack
void zigzag_order(TreeNode *root)
{
    stack<TreeNode *> s_odd;    //存奇数行
    stack<TreeNode *> s_even;   //存偶数行
    TreeNode * current = root;
    int level = 1;
    
    s_odd.push(current);
    while(!s_odd.empty() || !s_even.empty())
    {
        if(level%2 == 1)
        {
            current = s_odd.top();
            s_odd.pop();
            cout << current -> payload << " ";
            
            if(s_odd.empty())
                level++;
            
            if(current->left)
                s_even.push(current->left);
            
            if(current->right)
                s_even.push(current->right);
            
            
            
        }
        
        
        else    //偶数行
        {
            current = s_even.top();
            s_even.pop();
            cout << current->payload << " ";
            
            if(s_even.empty())
                level++;
            
            if(current->right)
                s_odd.push(current->right);
            
            if(current->left)
                s_odd.push(current->left);
        }
        
    }
    
}

//两个stack
void zigzag_order2(TreeNode *root)
{
    stack<TreeNode *> s_odd;    //存奇数行
    stack<TreeNode *> s_even;   //存偶数行
    TreeNode * current = root;
    int level = 0;
    
    s_odd.push(current);
    while(!s_odd.empty() || !s_even.empty())
    {
        if(level%2 == 0)
        {
            current = s_odd.top();
            s_odd.pop();
            cout << current -> payload << " ";
            
            if(s_odd.empty())
                level++;
            
            if(current->left)
                s_even.push(current->left);
            
            if(current->right)
                s_even.push(current->right);
            
            
            
        }
        
        
        else    //偶数行
        {
            current = s_even.top();
            s_even.pop();
            cout << current->payload << " ";
            
            if(s_even.empty())
                level++;
            
            if(current->right)
                s_odd.push(current->right);
            
            if(current->left)
                s_odd.push(current->left);
        }
        
    }
    
}

//两个stack
vector<vector<int>> zigzag_order_leetcode(TreeNode *root)
{
    stack<TreeNode *> s_odd;    //存奇数行
    stack<TreeNode *> s_even;   //存偶数行
    TreeNode * current = root;
    int level = 0;
    vector<vector<int>> result;
    vector<int> level_group;
    
    s_odd.push(current);
    while(!s_odd.empty() || !s_even.empty())
    {
        if(level%2 == 0)
        {
            current = s_odd.top();
            s_odd.pop();
            cout << current -> payload << " ";
            level_group.push_back(current->payload);
            
            if(s_odd.empty())
            {
                level++;
                result.push_back(level_group);
                level_group.clear();
            }
            
            if(current->left)
                s_even.push(current->left);
            
            if(current->right)
                s_even.push(current->right);
            
            
            
        }
        
        
        else    //偶数行
        {
            current = s_even.top();
            s_even.pop();
            cout << current->payload << " ";
            level_group.push_back(current->payload);
            
            if(s_even.empty())
            {
                level++;
                result.push_back(level_group);
                level_group.clear();
            }
            
            if(current->right)
                s_odd.push(current->right);
            
            if(current->left)
                s_odd.push(current->left);
        }
        
    }
    
    return result;
    
}

void post_order_test(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *current = root;
    TreeNode *previous = nullptr;//前一次访问的节点 默认为空
    
    s.push(current);
    while(!s.empty())
    {
        current = s.top();
 //       cout<< " current = " << current->payload << endl;
        if(  (current->left == nullptr && current->right == nullptr) || //两边都为空或者
           ( previous != nullptr && (previous == current->right || previous == current->left) ) )
        //或者previous在不为空的情况下 等于当前节点的左子树或者又子树
        //previous!=nullptr不能省略, 不然如果current某个子树为空, previous也为空就进入循环了, 而实际上并不应该进入
        {
            cout << current->payload << "  ";
            previous = current;
            s.pop();
        }
        
        else
        {
            if(current->right)
                s.push(current->right);
            
            if(current->left)
                s.push(current->left);
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
    root->left->left->right = new TreeNode(5);
    root->right->right->left = new TreeNode(14);
    
    
    //cout << "Node 4 left: " << root->left->right->left->payload << endl;
//    in_order3(root);
//    cout << endl;
//    level_order(root);
//    cout << endl;
//    zigzag_order(root);
//    cout << endl;
//    
//    vector<vector<int>> result;
//    
//    
//    result = zigzag_order_leetcode(root);
//    for(vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it)
//    {
//        for(vector<int>::iterator it2 = (*it).begin(); it2!= (*it).end();++it2)
//        {
//            cout << *it2 << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    post_order2(root);
    cout << endl;
    post_order_test(root);
    cout << endl;
    
    in_order(root);
    
    return 0;
    
    
}
