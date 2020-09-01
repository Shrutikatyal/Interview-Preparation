/*
 * Author : Shruti Katyal
 * Date   : 16 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
	
    vector<vector<string>> res;
    vector<bool> rowTracker;
    vector<bool> colTracker;
    vector<bool> hillTracker;
    vector<bool> daleTracker;
    int totalQueens;
    
public:
    void placeQueen(vector<string> &currBoard, int row, int col){
        currBoard[row][col] = 'Q';
        rowTracker[row] = colTracker[col] = hillTracker[row + col] = daleTracker[row - col + totalQueens - 1] = true;
    }
    
    void removeQueen(vector<string> &currBoard, int row, int col){
        currBoard[row][col] = '.';
        rowTracker[row] = colTracker[col] = hillTracker[row + col] = daleTracker[row - col + totalQueens - 1] = false;
    }
    
    bool isSafeToPlaceQueen(vector<string> currBoard, int row, int col){
        return !(rowTracker[row] || colTracker[col] || hillTracker[row + col] || daleTracker[row - col + totalQueens - 1]);
    }
    
    //place a queen in  column 
    void solveNQueensUtil(vector<string> currBoard, int currCol){
        if(currCol >= totalQueens){
            res.push_back(currBoard);
            return;
        }
        
        for(int currRow=0; currRow < totalQueens; currRow++){
            if(isSafeToPlaceQueen(currBoard,currRow,currCol)){
                placeQueen(currBoard,currRow,currCol);
                solveNQueensUtil(currBoard,currCol + 1);
                removeQueen(currBoard,currRow,currCol);
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        if(n==0) return {{}};
        
        if(n==1) return {{"Q"}};
        
        totalQueens = n;
        rowTracker = vector<bool>(n,false);
        colTracker = vector<bool>(n,false);
        hillTracker = vector<bool>(2*n-1,false);
        daleTracker = vector<bool>(2*n-1,false);
        
        vector<string> currBoard = vector<string>(n,string(n,'.'));
        
        solveNQueensUtil(currBoard,0);
        
        return res;
    }
};

