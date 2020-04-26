/*
 * Author : Shruti Katyal
 * Date   : 17 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int minAddToMakeValid(string S) {
        int count = 0, bal = 0;
        for(char ch:S) {
            count += (ch=='(')?1:-1;
            if(count==-1){
                bal++;
                count++;
            }
        }
        
        return bal+count;
    }
};
