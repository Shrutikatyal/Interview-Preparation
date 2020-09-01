/*
 * Author : Shruti Katyal
 * Date   : 04 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[256] = {0};
        bool visited[256] = {0};
        int pos = 0;
        string res = "";
        
        for(char ch:s) freq[ch]++;
        
        for(char ch:s){
            
            freq[ch]--;
            if(visited[ch]) continue;
            
            while(res!="" && ch < res.back() && freq[res.back()]){
                visited[res.back()] = false;
                res.pop_back();
            }
            
            visited[ch] = true;
            res += ch;
        }
        
        return res;
    }
};
