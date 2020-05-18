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

void getNextGreatest(vector<unsigned long> nums){
    stack<unsigned long> stk;
    vector<long> res(nums.size());
    
    for(int i=nums.size()-1; i >= 0; i--){
        while(!stk.empty() && stk.top() <= nums[i])
            stk.pop();
        
        res[i]=stk.empty()?-1:stk.top();
        stk.push(nums[i]);
    }
    
    for(int i=0; i<nums.size(); i++)
        cout<<res[i]<<" ";
        
    cout<<endl;
}

int main() {
	//code
	
	short T;
	cin>>T;
	
	while(T--){
	   int n;
	   cin>>n;
	   
	   vector<unsigned long> nums(n);
	   
	   for(int i=0; i < n; i++)
	        cin>>nums[i];
	   
	   getNextGreatest(nums);
	}
	return 0;
}
