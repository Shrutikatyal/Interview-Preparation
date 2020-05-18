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


void zigzag(vector<int> nums){
    bool small = true;
    
    for(int i=0; i < nums.size() - 1; i++){
        if(small && nums[i] > nums[i+1])
            swap(nums[i], nums[i+1]);
        else if(!small && nums[i] < nums[i+1])
            swap(nums[i], nums[i+1]);
        small = !small;
    }
    
    for(int i=0; i<nums.size(); i++)
        cout<<nums[i]<<" ";
    
    cout<<endl;
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
	   zigzag(nums);
	}
	return 0;
}
