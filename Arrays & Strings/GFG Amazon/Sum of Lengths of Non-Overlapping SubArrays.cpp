/*
 * Author : Shruti Katyal
 * Date   : 17 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int> nums, int k){
    int len = 0;
    bool found = false;
    for(int i=0; i < nums.size();){
        int count = 0;
        found = false;
        
        while(i<nums.size() && nums[i] <= k){
            count++;
            
            if(nums[i]==k)
                found = true;
        
            i++;
        }
        
        if(found)
          len += count;
          
        while(nums[i]>k && i<nums.size())
            i++;
    }
    
    return len;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	   int n;
	   cin>>n;
	    
	   vector<int> nums(n);
	    
	   for(int i=0; i<n; i++)
	        cin>>nums[i];
	        
	   int k;
	   cin>>k;
	   
	   cout<<maxLength(nums,k)<<"\n";
	}
	
	return 0;
}
