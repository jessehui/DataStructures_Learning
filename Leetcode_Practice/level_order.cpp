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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> level;
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        int level_num = 0;
        TreeNode *current = root;
        queue<TreeNode *> q;
        q.push(current);
        q.push(nullptr);
        
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
            else    //current == nullptr
            {
                result.push_back(level);
                level.clear();
                if(q.size() > 0)    //没有到最后一行
                    q.push(nullptr);
            }

        }
        return result;
    }
};