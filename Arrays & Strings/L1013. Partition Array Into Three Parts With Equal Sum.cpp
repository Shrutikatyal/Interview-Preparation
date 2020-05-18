/*
 * Author : Shruti Katyal
 * Date   : 17 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
	//Optimised
    bool canThreePartsEqualSum(vector<int>& A) {
        /*We can find our target sum by aggregating all numbers and dividing the result by 3.
         Then we sum numbers again and track how many times we get the target sum.
         If the total sum is zero then we can reach the sum more than 3 times
         10 -10 10 -10 10 -10 10 -10
        */
        
        int totalSum = 0;
        for(int num: A)
            totalSum += num;
        
        //If the cummulative sum is not a multiple of 3 then we cannnot partition our array
        if(totalSum % 3) return false;
        
        int sum = 0, part = 0;          //Part:Partition number
        for(int i=0; i < A.size() && part < (totalSum? 2 : 3); i++){
            sum += A[i];
            
               if (sum == totalSum / 3) {
                   part++;
                   sum = 0;
               }
        }
        
        
        return part == (totalSum? 2: 3);
    }
    
};
 
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        /*We can find our target sum by aggregating all numbers and dividing the result by 3.
         Then we sum numbers again and track how many times we get the target sum.
        */
        
        int totalSum = 0;
        for(int num: A)
            totalSum += num;
        
        //If the cummulative sum is not a multiple of 3 then we cannnot partition our array
        if(totalSum % 3) return false;
        
        int sum = 0, part = 0;          //Part:Partition number
        for(int i=0; i < A.size(); i++){
            sum+= A[i];
            
            if(sum == (part+1)*(totalSum/3))
                part++;
        }
        
        return part >= 3;
    }
};
