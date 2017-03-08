/*

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- 
whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, 
the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false,
 the order of elements returned by next should be: [1,4,6].

*/





/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {

private:
    queue<int> q;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
       // cout << "n = " << n << endl;
        for(int i = 0; i<n; i++)
        {
            if(nestedList[i].isInteger())
            {
                q.push(nestedList[i].getInteger());
            }
            else
            {
                vector<NestedInteger> temp = nestedList[i].getList();
                NestedIterator *it_temp = new NestedIterator(temp);     //call this function recursively
                while(it_temp->hasNext())
                {
                    q.push(it_temp->next());
                }

            }
        }
    }

    int next() {
        int num = q.front();
        q.pop();
        return num;
    }

    bool hasNext() {
        return !q.empty();
    }
};



//another method
//we can use recursive method, and also use stack

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */