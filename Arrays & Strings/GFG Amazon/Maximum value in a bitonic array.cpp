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

int maxInBitonic(vector<int> a){
    
    int low = 0, high = a.size()-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(mid==0 || mid==a.size()-1 || (a[mid] > a[mid+1] && a[mid] > a[mid-1]))
            return a[mid];
        else if( a[mid] > a[mid+1] )
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return a[low];   
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
	   cout<<maxInBitonic(nums)<<endl;
	}
	return 0;
}
