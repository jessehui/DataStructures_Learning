/*

Given two binary trees, write a 
function to check if they are equal or not.

Two binary trees are considered equal 
if they are structurally identical and the nodes have the same value.
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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if(p == nullptr && q == nullptr)
    		return true;
    	else
    		if(p == nullptr || q == nullptr)
    			return false;	

    	stack<TreeNode *> sta_p, sta_q;
    	sta_p.push(p);
    	sta_q.push(q);
        while(!sta_q.empty())
        {
        	if(sta_p.empty())
        		return false;

        	if(p == nullptr || q == nullptr)
        	{
        		if(!(q == nullptr && p == nullptr))
        			return false;
        		p = sta_p.top()->right;
        		sta_p.pop();
        		q = sta_q.top()->right;
        		sta_q.pop();
        	}

        	else 
        	{
        	    if(p->val != q->val)
        		    return false;
        		
                sta_p.push(p);
                sta_q.push(q);
            	p = p->left;
            	q = q->left;
        	}



        	
        }

        return true;
    }
};















