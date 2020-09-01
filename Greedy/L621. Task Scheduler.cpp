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
    int leastInterval(vector<char>& tasks, int n) {
        int map[26]={0};
        
        for(char ch: tasks) map[ch - 'A']++;
        
        sort(map, map+26);
        
        int maxVal = map[25] - 1, idle = maxVal * n;
        
        for(int i=24;i>=0 && map[i] > 0; i--)
            idle -= min(maxVal, map[i]);
        
        
        if(idle > 0)
            return idle + tasks.size();
        return tasks.size();
    }
};
 



