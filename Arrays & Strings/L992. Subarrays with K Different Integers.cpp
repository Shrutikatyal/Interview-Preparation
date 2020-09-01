/*
 * Author : Shruti Katyal
 * Date   : 27 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
 
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        int left = 0, right = 0, ans = 0, prefix = 0, distinct = 0;
        int map[20001]={0};
        
        for(left = 0, right = 0; right < A.size(); right++){

            if(++map[A[right]] == 1)
                distinct++;
            
            // clean up the window from too many distinct
            while(distinct > k){ if(--map[A[left]] == 0) {distinct--; prefix = 0;} left++;}
            
            // clean up the window from duplicates
            while(map[A[left]] > 1) { --map[A[left]]; prefix++; left++; }
            
            if(distinct == k)
                ans += prefix + 1;
            
        }
        
        return ans;
    }
};
