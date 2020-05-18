/*
 * Author : Shruti Katyal
 * Date   : 17 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void firstNegative(vector<int> nums, int k){
    
    deque<int> q;
    int i=0;
    
    for(; i<k; i++)
        if(nums[i] < 0)
            q.push_back(i);
            
    for(; i<nums.size(); i++){
        if(q.empty())
            cout<<0<<" ";
        else
            cout<<nums[q.front()]<<" ";
            
        while(!q.empty() && q.front()<= i-k)
            q.pop_front();
        
        if(nums[i]< 0)
            q.push_back(i);
    }
        
    if(q.empty())
        cout<<0<<" ";
    else
        cout<<nums[q.front()]<<" ";
        
    cout<<endl;    
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n, k;
	    cin>>n;
	    
	    vector<int> nums(n);
	    
	    for(int i=0; i<n; i++)
	        cin>>nums[i];
	   cin>>k;
	   firstNegative(nums,k);
	}
	return 0;
}
