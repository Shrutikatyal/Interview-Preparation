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

void findRepeatingAndMissing(vector<int> A){
    int n = A.size();
    
    for(int i=0; i < n; i++){
        int index = abs(A[i])-1;
        if( A[index]< 0 )
            cout<<index+1<<" ";
        else
            A[index] = -A[index];
    }
    
    for(int i=0; i<n; i++)
        if(A[i] > 0)
         cout<<i+1<<endl;
    
}

int main() {
	//code
	int T;
	cin>>T;
	
	while(T--){
	    int n;
	    cin>>n;
	    
	    vector<int> nums(n);
	    
	    for(int i=0; i < n; i++)
	        cin>>nums[i];
	        
	    findRepeatingAndMissing(nums);
	}
	return 0;
}
