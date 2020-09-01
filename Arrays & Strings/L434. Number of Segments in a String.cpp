/*
 * Author : Shruti Katyal
 * Date   : 02 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int countSegments(string s) {
        stringstream ss;
        
        ss << s;
        int ans = 0;
        
        while(ss>>s){
            ans++;
        }
        
        return ans;
    }
};
