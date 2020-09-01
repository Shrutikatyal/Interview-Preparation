class Solution {
public:
    string minWindow(string S, string T) {
        
        vector<vector<int>> dp(T.length(),vector<int>(S.length(),-1));
        
        for(int i=0; i < S.length();i++)
            if(S[i]==T[0]) dp[0][i] = i;
        
        for(int j=1; j < T.length();j++){
            int last = -1;
            for(int i=0; i < S.length(); i++){
                if(last >=0 && S[i]==T[j])
                    dp[j][i] = last;
                if(dp[j-1][i] >= 0)
                    last = dp[j-1][i];
            }
        }
        
        int start = 0, end = S.length();
        for(int e=0; e < S.length();e++){
            int s = dp[T.length()-1][e];
            if(s>=0 && e-s < end - start)
                start = s, end = e; 
        }
        
        return end < S.length() ? S.substr(start,end-start+1) : "";
    }
};

// S = "abcdebdde", T = "bde"
//     0   1   2   3   4   5   6   7   8  
// 0  -1   -1  -1  -1  1  -1   -1  -1  5
// 1                1           5   5   
    
// start = 1    end = 4
// e = 4   s = 1
