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
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0,1,0,-1};        // N,E,S,W
        int dy[4] = {1,0,-1,0};
        
        int dir = 0;        //North
        
        int curr_x=0, curr_y=0;
        
        set<pair<int, int>> obs;
        
        for(auto ob:obstacles)
            obs.insert(make_pair(ob[0],ob[1]));
        
        int maxDist = 0;
        
        for(int steps: commands)
            if(steps == -1)
                dir = (dir + 1) % 4;
            else if(steps == -2)
                dir = (dir + 3) % 4;
            else
                for(int i=0; i < steps; i++){
                    int x = curr_x + dx[dir];
                    int y = curr_y + dy[dir];
                    
                    if(obs.find(make_pair(x,y)) == obs.end()){
                        curr_x = x;
                        curr_y = y;
                        maxDist = max(maxDist, x*x + y*y);
                    }
                }
            
        return maxDist;
    }
};
