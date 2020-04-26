/*
 * Author : Shruti Katyal
 * Date   : 15 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> sum;
        //sum[i] = sum[0 to i]
        
        int count = 0,res=0;
        for(int i=0;i<hours.size();i++){
            
            count += (hours[i]>8)? 1 : -1;
            if(count>0)
                res = i+1;
            else {
                if(sum.find(count)==sum.end())
                    sum[count] = i;
                if(sum.find(count-1)!=sum.end())
                    res = max(res,i-sum[count-1]);
            }
        }
        
        return res;
        
    }
};
