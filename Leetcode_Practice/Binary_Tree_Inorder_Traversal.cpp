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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *current = root;
        vector<int> result;

        while(current != nullptr || s.empty() != true)
        {
			//先入栈所有左子树节点
			while(current != nullptr)
			{
				s.push(current);
				current = current->left;
			}      

			//此时current为nullptr 所以要先pop一个
			if(!s.empty())  	//不为空
			{
				current = s.top();
				s.pop();
		//		cout << current -> val << " ";
				result.push_back(current->val);
				current = current -> right;	//该节点打印完一定是打印右边的节点 如果右边没有就打印上一层(先pop)
			}
        }

        return result;


}
};


//Recursively
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
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {

        if(root)
        {
            inorderTraversal(root->left);
            result.push_back(root->val);
            inorderTraversal(root->right);
        }
        
        return result;
}
};