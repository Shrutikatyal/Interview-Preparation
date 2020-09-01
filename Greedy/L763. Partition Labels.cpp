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
    vector<int> partitionLabels(string S) {
        int lastIndex[26]={-1}, len = 0,j=0;
        vector<int> partitions;
        
        for(int i=0; i<S.length();i++) 
            lastIndex[S[i]-'a'] = i;
            
        for(int i=0; i < S.length(); i++,len++){
            j = max(lastIndex[S[i]-'a'],j);
            if(i==j)
            {
                partitions.push_back(len + 1);
                len = -1;       //Because iss iteration ke baad len++ hogi
            }
        }
        
        return partitions;
    }
};
