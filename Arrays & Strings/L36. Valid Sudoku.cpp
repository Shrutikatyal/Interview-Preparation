/*
 * Author : Shruti Katyal
 * Date   : 15 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> rows(9, vector<bool>(9,false));
        vector<vector<bool>> cols(9, vector<bool>(9,false));
        vector<vector<vector<bool>>> box(3,vector<vector<bool>>(3,vector<bool>(9,false)));
        
        for(int i=0; i < 9; i++)
            for(int j=0; j < 9; j++)
                if(board[i][j] != '.'){
                int num = board[i][j] - '0' - 1;
                if(rows[i][num] || cols[j][num] || box[i/3][j/3][num])
                    return false;
                rows[i][num] = cols[j][num] = box[i/3][j/3][num]= 1;
            }
        
        return true;
    }
};
