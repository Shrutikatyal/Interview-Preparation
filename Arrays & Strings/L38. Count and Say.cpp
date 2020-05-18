/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

#include<string>
class Solution {
public:
    string countAndSay(int n) {
        if(n==0)
            return "";
        
        string res = "1";
        while(--n)
        {
            string temp;
            for(int i=0;i<res.size();i++)
            {
                int count=1;
                while(i+1<res.size() and res[i]==res[i+1])
                {    
                    count++;
                    i++;
                }
                temp += to_string(count) + res[i];
            }
            res = temp;
        }
        
        return res;
    }
};
