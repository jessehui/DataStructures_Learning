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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        
        queue<TreeNode *> q;
        TreeNode * current = root;
        q.push(root);
        q.push(nullptr);
        vector<int> level;
        
        while(!q.empty())
        {
            current = q.front();
            q.pop();
            if(current != nullptr)
            {
                level.push_back(current->val);
                
                if(current->left)
                    q.push(current->left);
                
                if(current->right)
                    q.push(current->right);
            }
            else
            {
                if(!q.empty())
                    q.push(nullptr);
                result.push_back(level);
                level.clear();
                
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};