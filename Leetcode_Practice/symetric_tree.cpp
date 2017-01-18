/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3



*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//recursive method
class Solution {
public:

bool isSymmetric(TreeNode* root) {
    if(root == nullptr)
        return true;
    TreeNode *left_sub = root->left;
    TreeNode *right_sub = root->right;
    return isMirror(left_sub, right_sub);
}

bool isMirror(TreeNode *left_sub, TreeNode *right_sub )
{
    if(left_sub == nullptr && right_sub == nullptr)
    {
    //    cout << "end " << endl;
        return true;
    }
    
    else if(left_sub == nullptr || right_sub == nullptr)
        return false;
    
    if(left_sub->val == right_sub->val)
    {
        if(!isMirror(left_sub->left, right_sub->right))
        {
     //       cout << "out false" << endl;
            return false;
        }
        if(!isMirror(left_sub->right, right_sub->left))
        {
    //        cout << "inside false" << endl;
            return false;
        }
    }
    else 
    {
 //       cout << "val not match" << endl;
        return false;
    }
    
    return true;
    
}
};







//non recursively two queues
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

bool isSymmetric(TreeNode* root) {
    if(root == nullptr)
        return true;
    TreeNode *left_sub = root->left;
    TreeNode *right_sub = root->right;
    queue<TreeNode *> q_left, q_right;
    if(left_sub == nullptr || right_sub == nullptr)
    {
        if(!(left_sub == nullptr && right_sub == nullptr))//一个为空一个不为空
            return false;
        else return true;
    }
    
    if(left_sub->val != right_sub->val)
        return false;
    q_left.push(left_sub);
    q_right.push(right_sub);
    
    while(!q_left.empty() && !q_right.empty())
    {
        left_sub = q_left.front();
        q_left.pop();
        right_sub = q_right.front();
        q_right.pop();
        
        if(left_sub->left == nullptr || right_sub->right == nullptr)
        {
            if(!(left_sub->left == nullptr && right_sub->right == nullptr))
                return false;
            else goto right_;   //都为空 看右边
        }
        
        if(left_sub->left->val != right_sub->right->val)
            return false;
        else
        {
            q_left.push(left_sub->left);
            q_right.push(right_sub->right);
        }
        
    right_:
        if(left_sub->right == nullptr || right_sub->left == nullptr)
        {
            if(!(left_sub->right == nullptr && right_sub->left == nullptr))
                return false;
            else continue;  //都为空 结束这次循环 pop下一个
        }
        if(left_sub->right->val != right_sub->left->val)
            return false;
        else
        {
            q_left.push(left_sub->right);
            q_right.push(right_sub->left);
        }
        
    }
    
    return true;
    
    
}


};