/*
 * Author : Shruti Katyal
 * Date   : 06 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class KthLargest {
    priority_queue<int,vector<int>,greater<int>> aux; //minheap;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        
        size = k;
        
        for(int elt: nums){
            aux.push(elt);
            if(aux.size()>k)
                aux.pop();
        }
        
    }
    
    int add(int val) {
        aux.push(val);
        if(aux.size()>size)
            aux.pop();
        return aux.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
