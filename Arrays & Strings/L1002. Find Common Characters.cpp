/*
 * Author : Shruti Katyal
 * Date   : 17 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        vector<int> count(26,INT_MAX);
        vector<string> res;
        
        for(int i=0; i<A.size();i++){
            vector<int> countTemp(26,0);
            for(int j=0; j<A[0].size(); j++)
                countTemp[A[i][j]-'a']++;
            
            for(int j=0; j<26; j++)
                count[j] = min(count[j], countTemp[j]);
            
        }
        
        
        for(int i=0; i<26; i++)
            while(count[i] > 0){
                res.push_back(string(1,'a'+i));
                count[i]--;
            }
        
        return res;
                
    }
};
