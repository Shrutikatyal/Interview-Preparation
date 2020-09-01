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
    int compress(vector<char>& chars) {
        int i = -1, j=0;
        
        while(j<chars.size()){
            
            int count = 1;
            
            while(j<chars.size()-1 && chars[j]==chars[j+1]){
                count++;
                j++;
            }
                
            
            chars[++i] = chars[j++];
            if(count > 1){
                string c = to_string(count);
                for(char ch: c)
                    chars[++i] = ch;
            }
        }
        
        return i+1;
    }
};
