/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

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

//NULL is acceptable

//one case missing: if the right tree has a node smaller than the root, 
//it should be false, but the code will return true
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
        	return true;

        if( (root->left != nullptr && root->left->val > root->val ) || \
        (root->right != nullptr && root->right->val < root->val) )
        	return false;

        if(isValidBST(root->left) && isValidBST(root->right))
        	return true;
        else
        	return false;
    }
};



//another try 72/74 then bug
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if(root == nullptr)
			return true;

		return isValidBST(root, root->val);
	}


private:
    bool isValidBST(TreeNode* root, int root_val) {
        if(root == nullptr)
        	return true;

        if( (root->left != nullptr && root->left->val >= root->val ) || \
        (root->right != nullptr && root->right->val <= root->val) )
        	return false;

        if(root->val > root_val)	//right subtree
        {
        	if(root->left != nullptr && root->left->val <= root_val)
        		return false;
        }

        if(root->val < root_val)
        {
        	if(root->right != nullptr && root->right->val >= root_val)
        		return false;
        }

        if(isValidBST(root->left, root_val) && isValidBST(root->right, root_val))
        	return true;
        else
        	return false;
    }
};


//
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, nullptr, nullptr);
	}

private:
	bool isValidBST(TreeNode* root, TreeNode* min_Node, TreeNode* max_Node)
	{
		if(root == nullptr)
        	return true;

        //general
        if( (root->left != nullptr && root->left->val >= root->val ) || \
        (root->right != nullptr && root->right->val <= root->val) )
        	return false;

        //hierarchy
        if(root->left != nullptr && min_Node != nullptr && root->left->val <= min_Node->val)
        	return false;
        if(root->right != nullptr && max_Node != nullptr && root->right->val >= max_Node->val)
        	return false;

        if(isValidBST(root->left, min_Node, root) && isValidBST(root->right, root, max_Node))
        	return true;
        	
        return false;
	}
};









