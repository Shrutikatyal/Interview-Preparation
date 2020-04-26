/*
 * Author : Shruti Katyal
 * Date   : 15 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class MyStack {
    queue<int> queue1,queue2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(queue1.size()==0)
            return INT_MIN;
        while(queue1.size()>1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        
        int x = queue1.front();
        queue1.pop();
    
        while(!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }
        
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return queue1.back();   
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return !queue1.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
