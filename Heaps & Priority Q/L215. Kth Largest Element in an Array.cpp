/*
 * Author : Shruti Katyal
 * Date   : 06 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> aux; //minheap;
        int size = k;
        
        for(int elt: nums){
            aux.push(elt);
            if(aux.size()>k)
                aux.pop();
        }
        
        return aux.size()?aux.top():0;
    }
};
