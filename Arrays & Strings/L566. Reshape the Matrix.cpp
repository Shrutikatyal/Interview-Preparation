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
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() == 0 || r * c != nums.size()*nums[0].size()) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        int row = 0, col = 0;
        
        for(int i=0; i < nums.size(); i++)
            for(int j=0; j < nums[i].size(); j++){
                res[row][col++] = nums[i][j];
                if(col == c){
                    col = 0;
                    row++;
                }
            }
        
        return res;
    }
};
