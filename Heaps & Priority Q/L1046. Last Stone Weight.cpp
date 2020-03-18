/*
 * Author : Shruti Katyal
 * Date   : 06 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone: stones)
            pq.push(stone);
        
        while(pq.size()>1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first < second)
                pq.push(second-first);
            else if(second < first)
                pq.push(first-second);
        }
        
        return pq.size()? pq.top(): 0;
    }
};
