//too slow

class MinStack {
    
private: 
    vector<int> stack_sim;
    int minimal;
    
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    
    void push(int x) {
        stack_sim.push_back(x);
        if(stack_sim.size() <= 1  || x < minimal)
            minimal = x;
    }
    
    void pop() {
        vector<int> copy = stack_sim; 
        sort(copy.begin(),copy.end());//default: small -> big
        int x = stack_sim.back();   //top
        if(x == minimal)
            minimal = copy[1];
        stack_sim.pop_back();
    }
    
    int top() {
        int x = stack_sim.back();
        return x;
    }
    
    int getMin() {
        return minimal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

//faster solution
class MinStack {
    
private:
    vector<int> stack_sim;
    vector<int> min;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        min.push_back(INT_MAX);
    }
    
    void push(int x) {
        stack_sim.push_back(x);
        if(x <= min.back()) //假如有两个相等的最小的数 都要入栈
            min.push_back(x);
        
    }
    
    void pop() {
        int x = stack_sim.back();
        if(x == min.back())
        {
            min.pop_back();
        }
        stack_sim.pop_back();
        
    }
    
    int top() {
        return stack_sim.back();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */