/*
 * Author : Shruti Katyal
 * Date   : 17 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
            return false;
        preorder = preorder + ",";
        int capacity = 1;
        for(int i=0;i<preorder.size();i++){
            if (preorder[i]!=',') continue;
                capacity--;
            if (capacity<0) return false;
            if (preorder[i-1]!='#') capacity+=2;
        }
        
        return capacity==0;
    }
};
