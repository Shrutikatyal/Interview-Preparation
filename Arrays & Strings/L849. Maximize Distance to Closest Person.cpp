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
    int maxDistToClosest(vector<int>& seats) {
        
        int count = 0;    //count of zeroes
        int distance = 0, n = seats.size();
        
        for(int i=0; i < n; i++){
            count = seats[i]==0? count+1:0;
            distance = max(distance, (count+1)/2);   
        }
        
        //If the seats were empty in the begining then we need not place the subject in mid
        
        for(int i=0; i < n; i++)
            if(seats[i] == 1)
            {
                distance = max(distance, i);
                break;
            }
        
        
        //Similarly if the seats at the other end was all empty
        for(int i=seats.size()-1; i>=0 ; i--)
            if(seats[i] == 1)
            {
                distance = max(distance, n-i-1);
                break;
            }
   
        return distance;
    }
};

