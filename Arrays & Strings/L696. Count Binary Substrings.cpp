/*
 * Author : Shruti Katyal
 * Date   : 20 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    int countBinarySubstrings2(string s) {
        //NOT WORKING BUT WHY
        unordered_map<int,int> map;
        
        map[0] = 1;
        int ans = 0;
        int count = 0;
        
        for(int i=0; i<s.length(); i++){
            count += s[i]=='0'? -1 : +1;
            if(map[count])
               ans++;
            else
                map[count]++;
        }
        
        return ans;
    }
    
    /*First, I count the number of 1 or 0 grouped consecutively.
    For example "0110001111" will be [1, 2, 3, 4].

    Second, for any possible substrings with 1 and 0 grouped consecutively, the number of valid substring       will be the minimum number of 0 and 1.
    For example "0001111", will be min(3, 4) = 3, ("01", "0011", "000111")*/
    
    int countBinarySubstrings(string s) {
        
        int prevCount = 0, currCount = 1, count = 0;
        
        for(int i=1; i<s.length(); i++)
            if(s[i]==s[i-1])
                currCount++;
            else
            {
                count += min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }        
        
        return count + min(prevCount, currCount);
        
    }
    
    
};


// 0   0  1  1  0  0  1  1
// -1 -2 -1  0 -1 -2 -1  0
