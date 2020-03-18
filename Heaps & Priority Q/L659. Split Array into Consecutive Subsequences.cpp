/*
 * Author : Shruti Katyal
 * Date   : 08 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int> count, tail;
        
        for(int n : nums) count[n]++;

        for(int i : nums) {
            
            if(!count[i]) continue;
            
            count[i]--;
            
            //Adding to existing subsequence
            if(tail[i-1] > 0) {
                tail[i-1]--;
                tail[i]++;
            }
            //Creating new subsequence 
            else if(count[i+1] && count[i+2]) {
                count[i+1]--;
                count[i+2]--;
                tail[i+2]++;
            }
            else
                return false;
        }
        
        return true;
    }
};
