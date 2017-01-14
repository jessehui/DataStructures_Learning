class Queue {

private:
    stack<int>  s;
    stack<int> temp;
    
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        int t;
        while(s.size()>=2)
        {
            t = s.top();
            s.pop();
            temp.push(t);
        }
        s.pop();
        while(temp.size()!=0)
        {
            t = temp.top();
            temp.pop();
            s.push(t);
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> s_t = s;
        int t;
        while(s_t.size()>=2)
        {
            s_t.pop();
        }
        t = s_t.top();
        return t;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};