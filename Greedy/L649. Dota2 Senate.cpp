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
    string predictPartyVictory(string senate) {
        int score = 0; //+ve for R -ve for D
        
        //https://leetcode.com/problems/dota2-senate/discuss/105860/C%2B%2B-O(n)-solution
        
        for(int i=0; i<senate.size(); i++){
            
            if(senate[i]=='R' && score < 0) senate.push_back('D');
            else if(senate[i]=='D' && score > 0) senate.push_back('R');
            score = senate[i]=='R'? score + 1: score - 1;            
        }
        
        return score>0?"Radiant":"Dire";
        
    }
};




