/*
 * Author : Shruti Katyal
 * Date   : 07 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

struct myComparator{
    bool operator()(vector<int> a, vector<int> b){
        return a[0] + a[1] > b[0] + b[1];
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>,vector<vector<int>>,myComparator> q;
        
        if(nums1.size()==0 || nums2.size()==0 || k==0) return res;
        
        for(int i=0;i<nums1.size() && i<k;i++)
            q.push({nums1[i],nums2[0],0});
        
        int i=0;
        while(i<k && !q.empty()){
            vector<int> curr = q.top();
            q.pop();
            if(curr[2]+1 < nums2.size())
                q.push({curr[0], nums2[curr[2]+1],curr[2]+1});
            curr.pop_back();
            res.push_back(curr);
            i++;
        }
        
        return res;
    }
};
