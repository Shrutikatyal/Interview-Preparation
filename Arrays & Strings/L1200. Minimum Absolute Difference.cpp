/*
 * Author : Shruti Katyal
 * Date   : 19 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> res;
        int minDiff = INT_MAX;
        
        for(int i=0; i < arr.size()-1; i++)
            if(arr[i+1]-arr[i] < minDiff){
                minDiff = arr[i+1] - arr[i];
                res.resize(0);
                res.push_back({arr[i],arr[i+1]});
            }
            else if(arr[i+1]-arr[i] == minDiff)
                res.push_back({arr[i],arr[i+1]});
        
        return res;
    }
};
