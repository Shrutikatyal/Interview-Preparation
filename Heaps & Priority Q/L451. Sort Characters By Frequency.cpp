/*
 * Author : Shruti Katyal
 * Date   : 08 March, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> frequency;
        vector<string> buckets(s.size()+1,"");
        string res = "";
        
        for(char ch: s) 
            frequency[ch]++;
        
        for(auto pair: frequency) {
            int freq = pair.second;
            buckets[freq].append(freq,pair.first);  //append pair.first freq times
        }
        
        for(int i=s.size();i>0;i--)
           if(!buckets[i].empty())
               res += buckets[i];
        
        
        return res;
    }
};
