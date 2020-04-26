/*
 * Author : Shruti Katyal
 * Date   : 14 April, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        
        for(int i=0;i<asteroids.size();i++){
            
            if(asteroids[i]>0)
                res.push_back(asteroids[i]);
            else{
                //new left asteroid is bigger than rightmost asteroid
                while(!res.empty() && res.back()>0 && res.back()<abs(asteroids[i]))
                    res.pop_back();
                
                if(res.empty() || res.back()<0)
                    res.push_back(asteroids[i]);
                
                //both explodes
                else if(res.back()==abs(asteroids[i]))
                    res.pop_back();
            }
        }
        
        return res;
        
    }
};
