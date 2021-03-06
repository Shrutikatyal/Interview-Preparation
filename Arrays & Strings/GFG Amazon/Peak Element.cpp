/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakElement(int a[], int n)
{
   // Your code here
   int low = 0, high = n-1;
   
   while(low <= high){
       
       int mid = low + (high-low)/2;
       
       if(mid==0 && a[mid] >= a[mid+1] || mid==n-1 && a[mid] >= a[mid-1] || (a[mid] >= a[mid-1] && a[mid] >= a[mid+1]))
            return mid;
       
       if(mid == 0 || a[mid] > a[mid-1])
        low = mid + 1;
       else
        high = mid - 1;
   }
   
   return -1;
}

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}

	return 0;
}  // } Driver Code Ends
