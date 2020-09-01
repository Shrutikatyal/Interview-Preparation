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
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int count = 0;
        unordered_map<int,int> map;
        
        for(auto elt:dominoes){
            if(elt[0] > elt[1])
                map[elt[1]*9 + elt[0]]++;
            else
                map[elt[0]*9 + elt[1]]++;
        }
        
        for(auto elt:map)
            if(elt.second)
                count += elt.second*(elt.second-1)/2;
        
        return count;
    }
    
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int count = 0;
        unordered_map<int,int> map;
        
        for(auto elt:dominoes){
            if(elt[0] > elt[1])
                count += map[elt[1]*9 + elt[0]]++;
            else
                count += map[elt[0]*9 + elt[1]]++;
        }
        
        
        return count;
	}
};
