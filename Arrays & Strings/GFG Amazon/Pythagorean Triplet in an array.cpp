/*
 * Author : Shruti Katyal
 * Date   : 16 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void triplets(vector<int> nums){
    
    for(int i=0; i<nums.size(); i++)
        nums[i] = nums[i] * nums[i];
    
    sort(nums.begin(), nums.end());
    
    for(int i=nums.size()-1; i >=2; i--){
        int low = 0, high = i-1;
        while(low < high){
            if(nums[low]+nums[high] == nums[i]){
                cout<<"Yes"<<endl;
                return;
            }
            else if(nums[low]+nums[high] < nums[i])
                low++;
            else 
                high--;
        }
    }
    
    cout<<"No"<<endl;
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
	   triplets(nums);
	}
	return 0;
}
