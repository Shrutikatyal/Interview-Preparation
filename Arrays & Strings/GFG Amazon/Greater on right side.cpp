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

void getNextGreatest(vector<int> nums){
    vector<int> res(nums.size());
    int rightMax = -1;
    
    for(int i=nums.size()-1; i>=0; i--){
        res[i] = rightMax;
        if(nums[i] > rightMax)
            rightMax = nums[i];
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
	   
	   vector<int> nums(n);
	   
	   for(int i=0; i < n; i++)
	        cin>>nums[i];
	   
	   getNextGreatest(nums);
	}
	return 0;
}
