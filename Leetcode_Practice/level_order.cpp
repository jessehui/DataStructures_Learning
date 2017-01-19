/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//添加一个NULL作为flag 
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
                if(q.size() > 0)    //没有到最后一行 如果没有这个判断 会一直循环
                    q.push(nullptr);
            }

        }
        return result;
    }
};

//或者也可以用一个count作为计数 
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    if (root) 
        q.push(root);
    while (!q.empty()) {
        int len = q.size();
        vector<int> level;
        for (int i = 0;i < len;++i) {
            TreeNode *node = q.front();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            q.pop();
        }
        ans.push_back(level);
    }
    return ans;
}

//recursive method
class Solution {
public:
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    recur_levelOrder(result, root, 0);
    return result;
}

void recur_levelOrder(vector<vector<int>> &result, TreeNode *root, int level)
{
    if (!root)
    {
        return;
    }
    if ((level+1) > result.size())
    {
        result.push_back(vector<int> {});
    }
    result[level].push_back(root->val);
    recur_levelOrder(result, root->left, level+1);
    recur_levelOrder(result, root->right, level+1);
}
};