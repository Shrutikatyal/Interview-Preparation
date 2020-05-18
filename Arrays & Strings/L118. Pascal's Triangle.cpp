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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        int size=1;
        for(int i=0;i<numRows;i++)    
        {
            res[i].resize(size++);
            for(int j=0;j<size-1;j++)
            {
                if(j==0 or j==size-2)
                    res[i][j]=1;
                else
                    res[i][j]= res[i-1][j-1]+res[i-1][j];
            }    
        }    
        return res;
    }
};
