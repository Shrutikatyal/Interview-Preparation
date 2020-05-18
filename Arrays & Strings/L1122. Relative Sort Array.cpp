/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> res;
        map<int,int> count;
        
        for(int num:arr1)
            count[num]++;
        
        for(int num:arr2)
            while(count[num]-- > 0)
                res.push_back(num);
        
        for(auto num:count)
            while(num.second > 0)
            {
                res.push_back(num.first);
                num.second--;
            }
            
        
        return res;
    }
};
