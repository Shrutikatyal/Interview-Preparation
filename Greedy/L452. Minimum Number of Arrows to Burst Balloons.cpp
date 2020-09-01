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
    int findMinArrowShots(vector<vector<int>>& points) {
        //Sort points in increasing order of start points;
        sort(points.begin(), points.end());
        int ans = 0, minEnd = INT_MAX;
        
        for(int i=0; i<points.size(); i++)
            if(points[i][0] > minEnd)
                ans++, minEnd = points[i][1];
            else
                minEnd = min(minEnd,points[i][1]);
                
        return ans + !points.empty();
    }
};

//[1,6], [2,8], [7,12], [10,16]

