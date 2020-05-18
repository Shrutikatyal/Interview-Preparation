/*
 * Author : Shruti Katyal
 * Date   : 16 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;
vector<int> SortBinaryArray(vector<int> binArray);


 // } Driver Code Ends


//User function template for C++

// binArray is an array that consists only 0s and 1s
// return sorted binary array 
vector<int> SortBinaryArray(vector<int> A)
{
    // Your code goes here 
    int high = A.size() - 1;
    int low = 0;
    
    while(low < high){
        if(A[low] == 1 && A[high] == 0)
            swap(A[low++], A[high--]);
        
        if(A[low]==0)
            low++;
            
        if(A[high]==1)
            high--;
    }
    
    return A;
}


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> binArray(n);
	    
	    for(int i = 0; i  < n; i++)
	      cin>>binArray[i];
	      
	  	vector<int> result = SortBinaryArray(binArray);
	  	for(int i=0; i<n; i++)
	  	    cout<<result[i]<<" ";
	      
	    cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
