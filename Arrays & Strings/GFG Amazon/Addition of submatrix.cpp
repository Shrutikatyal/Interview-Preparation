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

void subMatrixSum(vector<vector<int>> A, int x1, int y1, int x2, int y2){
    int sum = 0;
    
    for(int i=min(x1,x2)-1; i <max(x1,x2); i++)
        for(int j=min(y1,y2)-1; j<max(y1,y2); j++)
            sum += A[i][j];
            
    cout<<sum<<endl;
}

int main() {
	//code
	
	int T;
	cin>>T;
	while(T--){
	    int n, m;
	    cin>>n>>m;
	    
	    vector<vector<int>> matrix(n,vector<int>(m,0));
	    
	    for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++)
	       cin>>matrix[i][j];
	       
	   int x1,y1,x2,y2;
	   
	   cin>>x1>>y1>>x2>>y2;
	   
	   subMatrixSum(matrix,x1,y1,x2,y2);
	}
	
	return 0;
}
