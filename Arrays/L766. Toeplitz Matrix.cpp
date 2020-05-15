/*
 * Author : Shruti Katyal
 * Date   : 15 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        for(int i=1; i < matrix.size(); i++)
            for(int j=1; j < matrix[0].size(); j++)
                if(matrix[i-1][j-1] != matrix[i][j])
                    return false;
        
        
        return true;
    }
};
