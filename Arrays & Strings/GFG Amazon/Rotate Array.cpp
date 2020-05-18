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

void leftRotate(vector<int> nums, int k){
    if(k){
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(), nums.begin()+nums.size()-k);
        reverse(nums.begin()+nums.size()-k, nums.end());
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
	    int n, k;
	    cin>>n>>k;
	    
	    vector<int> nums(n);
	    
	    for(int i=0; i<n; i++)
	        cin>>nums[i];
	   leftRotate(nums,k%n);
	}
	return 0;
}
