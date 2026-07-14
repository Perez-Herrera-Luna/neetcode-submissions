class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(regularStack.empty())
        {
            minStack.push(val);
            regularStack.push(val);
        }
        else
        {
            minStack.push(std::min(val, minStack.top()));
            regularStack.push(val);
        }
    }
    
    void pop() {
        regularStack.pop();
        minStack.pop();
    }
    
    int top() {
        return regularStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    std::stack<int> regularStack;
    std::stack<int> minStack;
};
