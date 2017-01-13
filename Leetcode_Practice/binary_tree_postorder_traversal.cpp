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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *current = root;
        TreeNode *previous = nullptr;
        vector<int> result;
        
        if(root == nullptr)
            return result;
        
        s.push(current);
        while(!s.empty())
        {
            current = s.top();
            
            if( (current->left == nullptr && current->right == nullptr) ||
            ( previous!=nullptr && (previous == current->right || previous == current->left)  )
            )
            {
                result.push_back(current->val);
                previous = current;
                s.pop();
            }
            
            
            else
            {
                //先入右后入左 因为打印的时候先打左 后打右
                if(current->right)
                    s.push(current->right);
                
                if(current->left)
                    s.push(current->left);
            }
        }
        
        return result;
    }
};