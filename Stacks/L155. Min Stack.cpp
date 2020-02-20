/*
 * Author : Shruti Katyal
 * Date   : 15 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
#include <stack> 
class MinStack {
    int min;
    stack<int> stacks;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;    
    }
    
    void push(int x) {
        if(x<=min)
        {
            stacks.push(min);
            min = x;
        }
        stacks.push(x);
        
    }
    
    void pop() {
        if(stacks.top()==min)
        {
            stacks.pop();
            min = stacks.top();
            
        }
        
        stacks.pop();
    }
    
    int top() {
        return stacks.top();
    }
    
    int getMin() {
        return min;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
