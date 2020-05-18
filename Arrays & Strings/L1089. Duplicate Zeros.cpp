/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int length = arr.size() - 1;
        int poss = 0;           //duplicate zeroes that can be accomodated
        
        
        for(int i=0; i <= length-poss; i++)
            if(arr[i] == 0){
                //Do not have cater this duplication and can handle it here only
                
                if(i == length - poss) {
                    arr[length] = 0;
                    length--;   //So that no one can modify
                    break;
                }
                
                poss++;
            }
        
        for(int i=length-poss; i>=0; i--){
            
            //That is why we handle edge case above
            if(arr[i]==0)
                arr[i + poss--] = 0;
            
            arr[i + poss] = arr[i]; 
        }
        
    }
};
