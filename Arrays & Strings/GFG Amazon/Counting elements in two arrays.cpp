/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
// { Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;
 
// function returns the index of largest element 
// smaller than equal to 'x' in 'arr'. For duplicates
// it returns the last index of occurrence of required
// element. If no such element exits then it returns -1. 
int binary_search(int arr[], int l, int h, int x);

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
void countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n);

// Driver program to test above
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        countEleLessThanOrEqual(arr1, arr2, m, n);
        cout<<endl;
    }
    return 0;
}// } Driver Code Ends


int binarySearch(int arr[], int n, int elt){
    int low = 0, high = n-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(arr[mid] <= elt)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return high+1;
}

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
void countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n)
{
//Your code goes here
    sort(arr2,arr2+n);
    
    for(int i=0; i < m; i++)
        cout<<binarySearch(arr2,n,arr1[i])<<" ";
    
}
