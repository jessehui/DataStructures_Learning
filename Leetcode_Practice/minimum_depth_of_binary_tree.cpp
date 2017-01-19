/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.

*/
//因为是从根节点到叶子节点 所以必须左右子树都为空才可以

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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode *> q;
        int level = 0;
        TreeNode * current;
        q.push(root);
        q.push(nullptr);    //use to seperate different level

        while(!q.empty())
        {
            current = q.front();
            q.pop();
            if(current != nullptr)
            {
                if(current->left)
                {
                    q.push(current->left);
                }
                // else 
                //     break;
                if(current->right)//there is right subtree
                {
                    q.push(current->right);
                }
                // else
                //     break;
                
                else
                if(!current->left)  //both are null
                    break;
                
            }
            else    //nullptr
            {
                level++;
                if(!q.empty())
                    q.push(nullptr);
            }
        }

        return level+1;
        
    }
};