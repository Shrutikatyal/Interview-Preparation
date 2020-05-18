/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

#include <iostream>
using namespace std;

int findMinLength(int arr[], int n, int elt){
    
    int minLength = n + 1, sum = 0;
    
    int start = 0, end = 0;
    
    while(end < n){
        
        while(sum <= elt && end < n)
            sum += arr[end++];
            
        while(sum > elt && start < end){
            
            minLength = min(minLength, end-start);
            sum = sum - arr[start++];
        }    
        
    }
    
    return minLength;
}

int main() {
	//code
	int T;
	cin>>T;
	
	while(T--){
	    int n, elt;
	    cin>>n>>elt;
	    
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	   
	   cout<<findMinLength(arr,n,elt)<<endl;
	}
	return 0;
}
