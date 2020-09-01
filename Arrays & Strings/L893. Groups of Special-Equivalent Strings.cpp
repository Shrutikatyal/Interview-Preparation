/*
 * Author : Shruti Katyal
 * Date   : 20 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
       
        //Just see which all chars are at even and odd positions resp.
        
        set<string> traversed;
        
        for(string s: A){
            string even, odd;
            for(int i=0; i<s.size(); i++)
                if(i%2)
                    odd += s[i];
                else
                    even += s[i];
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            traversed.insert(even+odd);
        }
        
        return traversed.size();
    }
};


