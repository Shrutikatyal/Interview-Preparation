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
    vector<int> dailyTemperatures(vector<int>& T) {
        
        vector<int> res(T.size(),0);
        stack<int> stk;
        
        for(int i=T.size()-1; i>=0 ;i--){
            while(!stk.empty() && T[i] >= T[stk.top()])
                stk.pop();
            res[i] = stk.empty()? 0 : stk.top()-i;
            stk.push(i);
        }
            
        return res;
    }
};
