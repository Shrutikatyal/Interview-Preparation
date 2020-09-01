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
    string reverseWords(string s) {
        int start = -1, end = -1;

        for(int i=0; i < s.length(); i++){
            
            if(s[i] == ' '){
                cout<<end<<" ";
                reverse(s.begin()+start+1, s.begin()+end+1);
                start = i;
                end = i;

            }
            else
                end++;
            
        }
        
        reverse(s.begin()+start+1, s.begin()+end+1);
        
        return s;
    }
};
