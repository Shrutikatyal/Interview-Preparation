/*
 * Author : Shruti Katyal
 * Date   : 03 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) { 
        auto comp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        };
        
        sort(people.begin(), people.end(), comp);
        
        vector<vector<int>> queue;
        for(auto p:people)
            queue.insert(queue.begin() + p[1],p);
            
        
        return queue;
    }
};
