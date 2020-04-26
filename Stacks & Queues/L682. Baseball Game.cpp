/*
 * Author : Shruti Katyal
 * Date   : 15 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> Stack;
        int sum = 0;
        
        for(string str:ops) {
            if(str=="C"){
                int invalid = Stack.top();
                Stack.pop();
                sum -= invalid;
            }
            else if(str=="D"){
                int score = 2*Stack.top();
                Stack.push(score);
                sum += score;
            }
            else if(str=="+"){
                int score1 = Stack.top();
                Stack.pop();
                int score2 = Stack.top();
                Stack.pop();
                Stack.push(score2);
                Stack.push(score1);
                int score3 = score1 + score2;
                sum += score3;
                Stack.push(score3);
            }
            else{
                int score = stoi(str);
                sum += score;
                Stack.push(score);
            }
        }
        
        return sum;
    }
};
