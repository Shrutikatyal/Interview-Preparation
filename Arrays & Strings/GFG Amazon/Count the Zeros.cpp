/*
 * Author : Shruti Katyal
 * Date   : 16 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
 #include <iostream>
using namespace std;

int countZeroes(int arr[], int n) {
    // code here
    int low=0, high = n-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(arr[mid]==0 && (mid==low || arr[mid-1]==1))
            return mid;
        else if(arr[mid])
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
	   
	   int nums[n];
	   
	   for(int i=0; i < n; i++)
	        cin>>nums[i];
	   
	   int count = countZeroes(nums,n);
	   if(count == -1)
	    cout<<0;
	   else
	    cout<<n-count;
	    
	    cout<<endl;
	      
	}
	return 0;
}
