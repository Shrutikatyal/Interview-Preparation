/*
 * Author : Shruti Katyal
 * Date   : 15 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class MyQueue {
    stack<int> stack1,stack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stack1.size()==0)
            return INT_MIN;
        
        while(stack1.size()>1) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        
        int x = stack1.top();
        stack1.pop();
        
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(stack1.size()==0)
            return INT_MIN;
        
        while(stack1.size()>1) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        
        int x = stack1.top();
        
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !stack1.size();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
