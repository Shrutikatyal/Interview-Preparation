/*
 * Author : Shruti Katyal
 * Date   : 16 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void maxInKSubArray(vector<int> nums, int k){
    
    deque<int> q(k);
    int i=0;
    for( ; i < k; i++){
     while(!q.empty() && nums[q.back()] <= nums[i])
        q.pop_back();
    
     q.push_back(i);    
    }    
    
    for( ; i < nums.size(); i++){
        cout<< nums[q.front()]<<" ";
        
        while(!q.empty() && q.front()<= i-k)
            q.pop_front();
            
        while(!q.empty() && nums[q.back()] <= nums[i])
            q.pop_back();
        q.push_back(i);
    }
    cout<<nums[q.front()]<<endl;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n, k;
	    cin>>n>>k;
	    
	    vector<int> nums(n);
	    
	    for(int i=0; i<n; i++)
	        cin>>nums[i];
	   maxInKSubArray(nums,k);
	}
	return 0;
}
