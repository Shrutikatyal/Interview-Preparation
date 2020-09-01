/*
 * Author : Shruti Katyal
 * Date   : 03 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num = to_string(N);
        int i, n = num.length();
        
        for(i=0;i<n-1 && num[i]<=num[i+1];i++);
        if(i==n-1) return N;
        int temp = num[i];
        
        for( ; i>=0 && num[i]==temp;i--) num[i]--; 
        
        for(i=i+2; i < n; i++) num[i]='9';
        
        return stoi(num);
    }
};
