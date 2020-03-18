/*
 * Author : Shruti Katyal
 * Date   : 06 February, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

class myComparator 
{ 
public: 
    int operator() (const vector<int> v1, const vector<int> v2) 
    { 
        return v1[0] > v2[0]; 
    } 
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<vector<int>,vector<vector<int>>,myComparator> queue;
        vector<int> uglyNum(n);
        uglyNum[0] = 1;
        
        //It's like merging K-sorted lists
        //https://leetcode.com/problems/super-ugly-number/discuss/277313/My-view-of-this-question-hope-it-can-help-you-understand
        
        for(int i=0;i<primes.size();i++)
            queue.push({primes[i],primes[i],0});
        
        //(val,which_prime_list_does_it_belongs,index_in_that_list)
        
        int i=1;
        while(i<n){
            
            vector<int> nextNum = queue.top();
            queue.pop();
    
            int val = nextNum[0], prime = nextNum[1], index = nextNum[2];
    
            if(uglyNum[i-1]!=val)
                uglyNum[i++] = val;
            
            queue.push({prime*uglyNum[index+1],prime,index+1});
        }
        
        return uglyNum[n-1];
    }
};
