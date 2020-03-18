/*
 * Author : Shruti Katyal
 * Date   : 07 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
struct myComp{
    bool operator()(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, myComp> q;
        
        for(int col=0;col<matrix[0].size() && col<k;col++)
            q.push({matrix[0][col],0,col});
        
        int i=0;
        vector<int> curr;
        while(i<k && !q.empty()){
            curr = q.top();
            q.pop();
            if(curr[1]+1 < matrix.size())
                q.push({matrix[curr[1]+1][curr[2]], curr[1]+1, curr[2]});
            i++;
        }
        
        return curr[0];
    }
};


//BINARY SEARCH
class Solution {
public:
    //O(n) time complexity
    int countLessThanEqual(vector<vector<int>> matrix, int elt,vector<int> &smallLargePair){
        int count = 0;
        int n = matrix.size();
        int row = n-1, col = 0;
        
        while(row>=0 && col<n) {
            if(matrix[row][col] > elt)
                smallLargePair[1] = min(matrix[row--][col],smallLargePair[1]);
            else {
                smallLargePair[0] = max(matrix[row][col++],smallLargePair[0]); 
                count += row + 1;
            }
        }
        
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int start = matrix[0][0], end = matrix[n-1][n-1], mid;
        
        while(start < end) {
            mid = (start + end)/2;
            vector<int> smallLargePair = {matrix[0][0], matrix[n-1][n-1]};
            
            int count = countLessThanEqual(matrix, mid, smallLargePair);
            //cout<<mid<<" "<<count<<" "<<smallLargePair[0]<<" "<<smallLargePair[1]<<"\n";
            
            if(count == k)
                return smallLargePair[0];
            
            if(count < k)
                start = smallLargePair[1];    //search higher
            else
                end = smallLargePair[0];      // search lower
        }
        
        return start;
    }
};
