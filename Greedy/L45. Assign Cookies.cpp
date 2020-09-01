/*
 * Author : Shruti Katyal
 * Date   : 01 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i=0,j=0;    //i for child and j for cookie
        
        while(i < g.size() && j < s.size())
            if(g[i] <= s[j])
                i++,j++;
            else
                j++;
        
        
        return i;
    } 
    
    int findContentChildren2(vector<int>& g, vector<int>& s) {
        int maxContent = 0;
        sort(s.begin(), s.end());
        for(int i=0; i < g.size(); i++)
            if(lower_bound(s.begin(),s.end(),g[i]) != s.end())
                maxContent++, s.erase(lower_bound(s.begin(),s.end(),g[i]));
        
        return maxContent;
    } 
};
