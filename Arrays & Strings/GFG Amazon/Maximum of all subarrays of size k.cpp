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
    for(int i=0; i <= nums.size()-k; i++){
        int max = nums[i];
        for(int j=1; j< k; j++)
            if(nums[j+i] > max)
                max = nums[i+j];
        cout<< max<<" ";
    }
    
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
	   maxInKSubArray(nums,k);
	}
	return 0;
}
