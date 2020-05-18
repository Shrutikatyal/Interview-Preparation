// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else 
        cout<<"0"<<endl;
	}
    return 0;
}// } Driver Code Ends


/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
bool findTriplets(int arr[], int n)
{ 
    //Your code here
    sort(arr, arr+n);
    for(int i=0; i < n; i++){
        int low = 0, high = i-1;
        while(low < high){
            if(arr[low] + arr[high] + arr[i] == 0)
                return true;
            if(arr[low] + arr[high] + arr[i] < 0)
                low = low + 1;
            else
                high = high - 1;
        }
    }
    
    return false;
}
