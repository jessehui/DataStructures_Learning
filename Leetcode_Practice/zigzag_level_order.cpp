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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    stack<TreeNode *> s_odd;    //存奇数行
    stack<TreeNode *> s_even;   //存偶数行
    TreeNode * current = root;
    int level = 0;
    vector<vector<int>> result;
    vector<int> level_group;
    
    if(current)
        s_odd.push(current);
    else
        return result;
        
    while(!s_odd.empty() || !s_even.empty())
    {
        if(level%2 == 0)
        {
            current = s_odd.top();
            s_odd.pop();
            cout << current -> val << " ";
            level_group.push_back(current->val);
            
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
            cout << current->val << " ";
            level_group.push_back(current->val);
            
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

};