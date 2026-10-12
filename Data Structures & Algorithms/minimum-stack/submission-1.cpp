class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);

        // 第 0 個元素
        if(min_stk.empty())
            min_stk.push(val);
        else
        {
            // 第一個才能用上一個跑
            if(min_stk.top() <= val)
                // min_stk.push(stk.getMin()); // 不能直接叫 getMin 因為 
                min_stk.push(min_stk.top());
            else
                min_stk.push(val);
        }
        
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
