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

int firstOccurrence(vector<int> arr, int elt){
    
    int low = 0, high = arr.size()-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid]==elt && (mid==0 || arr[mid]>arr[mid-1]))
            return mid;
        else if(arr[mid] < elt)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;
}

int lastOccurrence(vector<int> arr, int elt){
    
    int low = 0, high = arr.size()-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid]==elt && (mid==high || arr[mid]<arr[mid+1]))
            return mid;
        else if(arr[mid] <= elt)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -3;
}

int countOccurrence(vector<int> nums, int elt){
    int left = firstOccurrence(nums,elt);
    int right = lastOccurrence(nums,elt);
    return right-left+1;
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
	   cout<<countOccurrence(nums,k)<<endl;
	}
	return 0;
}
