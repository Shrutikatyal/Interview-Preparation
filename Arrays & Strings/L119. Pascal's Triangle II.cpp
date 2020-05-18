/*
 * Author : Shruti Katyal
 * Date   : 13 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,0);
        result[0]=1;
        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=i;j>0;j--)
                result[j]=result[j]+result[j-1];
        }
        
        return result;
    }
};
