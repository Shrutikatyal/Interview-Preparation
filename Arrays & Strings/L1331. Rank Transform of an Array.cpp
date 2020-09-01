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
    vector<int> arrayRankTransform(vector<int>& arr) {
       map<int,vector<int>> count;    //[elt => indexes]
        
       for(int i=0; i<arr.size(); i++)
            count[arr[i]].push_back(i);   
       
       int i = 1; 
       for(auto elt:count){
           
           for(auto index: elt.second)
               arr[index] = i;
           i++;
       }
        
        return arr;
    }
};
