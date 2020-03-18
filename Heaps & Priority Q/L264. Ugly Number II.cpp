/*
 * Author : Shruti Katyal
 * Date   : 06 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> k(n);
        k[0]=1;
        int t2=0,t3=0,t5=0;
        for(int i=1;i<n;i++){
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++;
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        
        return k[n-1];
    }
};
