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

int twoSum(vector<int> nums, int target){
    int count = 0;
    unordered_map<int, int> map;
    
    for(int num:nums){
        if(map[target-num])
            count += map[target-num];
        map[num]++;
    }
    
    return count;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n,k;
	    cin>>n>>k;
	    
	    vector<int> nums(n);
	    
	    for(int i=0; i<n; i++)
	        cin>>nums[i];
	   cout<<twoSum(nums,k)<<endl;
	}
	return 0;
}
