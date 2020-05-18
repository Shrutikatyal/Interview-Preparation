/*
 * Author : Shruti Katyal
 * Date   : 15 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(int i=0;i<flowerbed.size() && n;i++){
            if(!flowerbed[i] && (i==0 || !flowerbed[i-1]) && (i==flowerbed.size()-1 || !flowerbed[i+1])){
                n--;
                flowerbed[i] = 1;
            }    
        }
            
        return n==0;
    }
};

