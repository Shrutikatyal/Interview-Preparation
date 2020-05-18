/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int firstOccurrenceOfOne(vector<int> bits){
    int low = 0, high = bits.size()-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(bits[mid] == 1 && (mid==0 || bits[mid-1]==0))
            return mid;
        
        if(bits[mid] == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;
}

int main() {
	//code
	
	int T;
	cin>>T;
	
	while(T--){
	    int n;
	    cin>>n;
	    
	    vector<int> bits(n);
	    
	    for(int i=0; i < n; i++)
	        cin>>bits[i];
	        
	    cout<<firstOccurrenceOfOne(bits)<<endl;
	}
	
	return 0;
}
