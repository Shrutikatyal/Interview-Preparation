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
    int heightChecker(vector<int>& heights) {
        vector<int> count(100,0);
        
        for(int ht: heights)
            count[ht-1]++;
        
        int misMatch = 0;
        int currHeight = 1;
        
        for(int i=0; i < heights.size(); i++){
            while(count[currHeight-1] == 0){
                currHeight++;
            }
            
            if(currHeight != heights[i])
                misMatch++;
            
            //Yeh place ho gya
            count[currHeight-1]--;
            
        }
        
        return misMatch;
    }
};
