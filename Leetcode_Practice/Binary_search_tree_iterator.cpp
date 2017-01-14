/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {

private:
    stack<TreeNode *> s;

    
public:
    BSTIterator(TreeNode *root) {
        store_left(root);
    }
    
    //put all left node to the stack
    void store_left(TreeNode *root)
    {
        TreeNode *current = root;
        while(current)
        {
            s.push(current);
            current = current->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * current;
        int val;
        current = s.top();
        s.pop();
        val = current->val;

        //如果右边有节点 对右子树进行存储 
        if(current->right)
            store_left(current->right);
        
        return current->val;
            
    
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */