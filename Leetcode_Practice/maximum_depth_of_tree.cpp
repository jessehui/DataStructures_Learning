/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest 
path from the root node down to the farthest leaf node.

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

//wrong
class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<TreeNode*> s;
        int depth = 1;
        int max = 1;

        if(root == nullptr)
        	return 0;

        
        while(root != nullptr || !s.empty())
        {
        	s.push(root);
        	root = root->left;
        	depth++;

        	if(root == nullptr)
        	{
        		depth--;
        		root = s.top();
        		s.pop();
        		if(root->right != nullptr)
        		{
        			root = root->right;
        			depth++;
        		}
        		else
        		{
        			if(s.empty())
        				break;
        			else
        			{
        				root = s.top();
        				s.pop();
        				depth--;
        			}
        		}

        	}
           
        }

        return max;

    }
};



//fatal problem
class Solution {
public:
    int maxDepth(TreeNode* root) {
    	stack<TreeNode*> s;
    	TreeNode* current = root;
    	int max = 0;
    	int depth = 0;

    	while(current != nullptr)
    	{
    		depth++;
    		if(current->right != nullptr)
    		{
    			s.push(current->right);
    		}
    		else
    			depth--;

    		if(current->left != nullptr)
    		{
 				//depth++;
    			current = current->left;
    		}
    		else
    		{
    			if(max < depth)
    				max = depth;
    				
    			if(current->right == nullptr)
    			    depth--;

    			if(s.empty())
    				current = nullptr;
    			else
    			{
    				current = s.top();
    				s.pop();
    				
    			}
    		}

    	}

    	return max;

    }
};




//
class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<TreeNode*> s;
        int depth = 1;
        int max = 1;

        if(root == nullptr)
        	return 0;

        
        while(root != nullptr || !s.empty())
        {
        	s.push(root);
        	root = root->left;
        	depth++;
        		
        	while(root == nullptr)
        	{
        		depth--;
        		root = s.top->right;
        		s.pop();
        	}

        	if(depth>max)
        		max = depth;


        }

        return max;

    }
};

//solution
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
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

