class Stack {
    
private: 
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q.size() <= 1)
            q.pop();
        else
        {
            int temp = q.front();
            q.front() = q.back();
            q.pop();
            q.back() = temp;
            for(int i = 0; i< q.size()-1;i++)
            {
                temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
        
        
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};