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
    bool checkPalindrome(string s, int i, int j){
        while(i < j)
            if(s[i++]!=s[j--])
                return false;
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int i=0, j = s.length()-1;
        
        while(i < j){
            if(s[i]!=s[j])
                return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1);
            i++,j--;
        }
        
        return true;
    }
    
    //Another way
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j]) {
                int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
                while (i1 < j1 && s[i1] == s[j1]) {i1++; j1--;};
                while (i2 < j2 && s[i2] == s[j2]) {i2++; j2--;};
                return i1 >= j1 || i2 >= j2;
            }
        return true;
    }
};
