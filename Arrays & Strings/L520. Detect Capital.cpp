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
    bool detectCapitalUse(string word) {
        int capital = 0;
        
        for(int i=0; i < word.length(); i++)
            if(word[i] >= 'A' && word[i]<='Z')
                if(capital > 0 || i==0)
                    capital++;
                else
                    return false;
        
        return capital< 2 || capital==word.length();
    }
};
