/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
    vector<string> permutations;
public:
    void dfs(string S,int index,string path)
    {
        if(index==S.size())
        {
            permutations.push_back(path);
            return;
        }
        
        if(isalpha(S[index]))
        {
            dfs(S,index+1,path + (char)(S[index] | ' '));
            dfs(S,index+1,path + (char)(S[index] & '_'));
        }
        else
            dfs(S,index+1,path+S[index]);
        
    }
    
    vector<string> letterCasePermutation(string S) {
        
        dfs(S,0,"");
        return permutations;
    }
};
