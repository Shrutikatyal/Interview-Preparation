/*
 * Author : Shruti Katyal
 * Date   : 14 April, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
 class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j=0;
        int numOfPush = pushed.size();
        
        for(int i=0;i<numOfPush;i++){
            
            stk.push(pushed[i]);
            
            while(!stk.empty() && j < numOfPush && stk.top()==popped[j]) {
                stk.pop();
                j++;
            }
            
        }
        
        return j==numOfPush;
    }
};


