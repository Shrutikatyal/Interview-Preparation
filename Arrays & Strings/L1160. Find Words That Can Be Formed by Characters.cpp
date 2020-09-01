/*
 * Author : Shruti Katyal
 * Date   : 19 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        vector<int> count(26);
        int len = 0;
        
        for(char ch: chars)
            count[ch-'a']++;
        
        for(auto word: words){
            vector<int> temp = count;
            int i;
            for(i=0; i < word.length(); i++)
                if(--temp[word[i] - 'a'] < 0)
                    break;
            
            if(i == word.length())
                len += word.length();
        }
        
        return len;
    }
};
