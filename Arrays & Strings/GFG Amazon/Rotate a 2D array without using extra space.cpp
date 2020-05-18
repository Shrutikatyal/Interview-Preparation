/*
 * Author : Shruti Katyal
 * Date   : 16 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> A, int n){
    
    //transpose the matrix
    for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
       swap(A[i][j],A[j][i]);
    
    //reverse each column for anti-clock
    //reverse each column for clock
    for(int i=0; i<n; i++)
    for(int j=0, k=n-1; j<k; j++,k--)
        swap(A[i][j],A[i][k]);
    
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cout<<A[i][j]<<" ";
     
    cout<<endl;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    
	    vector<vector<int>> nums(n,vector<int>(n));
	    
	    for(int i=0; i<n; i++)
	    for(int j=0; j<n; j++)
	        cin>>nums[i][j];
	   rotateMatrix(nums,n);
	}
	return 0;
}
