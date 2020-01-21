/*
 * Author : Shruti Katyal
 * Date   : 19 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Binary watch
 */
 
#include<string>
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        
        vector<string> res;
        
        for(int h=0;h<12;h++)
          for(int m=0;m<60;m++)
            if(bitset<10>(h << 6 | m).count()==num)
                res.push_back(to_string(h) + (m>9?":" : ":0") + to_string(m));
        
        return res;
    }
};
