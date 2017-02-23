/*
One way to serialize a binary tree is to use pre-order traversal. 
When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the
 string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether
 it is a correct preorder traversal serialization of a binary tree. 
 Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer 
or a character '#' representing null pointer.

You may assume that the input format is always valid, for example 
it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false

*/






class Solution {
private:
    vector<string> str_to_vec(string preorder)
    {
        vector<string> pre_order_str;
        int index = 0;
        for(int i = 0; i<preorder.size();i++)
        {
            if(preorder[i] == ',')
            {
                string temp = preorder.substr(index, 1);
            //  cout << "temp = " << temp << " ";
                pre_order_str.push_back(temp);
                index = i+1;
            }
        }
        string temp = preorder.substr(index,1);
        pre_order_str.push_back(temp);

        return pre_order_str;


        // for(int i = 0; i<pre_order_str.size(); i++)
        //  cout << pre_order_str[i] << endl;
    }



public:

    bool isValidSerialization(string preorder) {
        vector<string> PO_str = str_to_vec(preorder);
        int size = PO_str.size();
        while(PO_str.size() > 1)
        {
            size = PO_str.size();
            for(int i = 0; i < size-2; i++)
            {
                if(PO_str[i] != "#")
                {
                    if(PO_str[i+1] == "#" && PO_str[i+2] == "#")
                    {
                        PO_str[i] = "#";
                        PO_str.erase(PO_str.begin()+i+1, PO_str.begin()+i+3);
                    }
                }
            
            }

            // for(auto it = PO_str.begin(); it != PO_str.end(); it++)
            //     cout << *it << " ";
            // cout << endl;
            

            if(size == PO_str.size())
            {
                return false;
            }
        }

        if(PO_str[0] == "#")
            return true;
        else
            return false;
    }
};








