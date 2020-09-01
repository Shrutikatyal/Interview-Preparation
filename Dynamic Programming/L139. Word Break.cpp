/*
 * Author : Shruti Katyal
 * Date   : 09 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length()==0) return false;
        
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        
        for(int i = 1; i <= s.size(); i++)
            for(int j=0;j<i;j++)
                if(dp[j] && dict.find(s.substr(j,i-j)) != dict.end() ){
                    dp[i] = true;
                    false;
                }
        
        return dp[s.size()];
    }
};
