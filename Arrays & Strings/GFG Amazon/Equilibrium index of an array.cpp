/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
// { Driver Code Starts
#include <iostream>
using namespace std;
#include <stdio.h>
 
int findEquilibrium(int [], int );
 
int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<findEquilibrium (a,n)<<endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends


/* You are required to complete this method*/
int findEquilibrium(int A[], int n)
{
  //Your code here
  int totalSum = 0;
  
  for(int i=0; i < n; i++)
    totalSum += A[i];
  
  int leftSum = 0;
  
  for(int i=0; i < n; i++){
      
      if(leftSum == totalSum - leftSum - A[i])
        return i;
      
      leftSum += A[i];
  }
  
  return -1;
}
