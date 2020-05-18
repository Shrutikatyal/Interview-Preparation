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

bool canBeSwapped(vector<int> arr1, vector<int> arr2){
    
    int sum1 = 0, sum2 = 0;

    for(int i=0; i < arr1.size(); i++)
        sum1 += arr1[i];
        
    for(int i=0; i < arr2.size(); i++)
        sum2 += arr2[i];
        
    if((sum1-sum2)%2)
    	return false;
    	
    int target = (sum1 - sum2)/2;
    
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    
    int i = 0, j = 0;
    
    while(i < arr1.size() && j < arr2.size()){
        int diff = arr1[i] - arr2[j];
        
        if(diff == target)
            return true;
            
        else if(diff < target)
            i++;
        else
            j++;
    }
 
    return false;  
}

int main() {
	//code
	
	int T;
	cin>>T;
	
	while(T--){
	    int n, m;
	    cin>>n>>m;
	    
	    vector<int> arr1(n);
	    vector<int> arr2(m);
	    
	    for(int i=0;i<n;i++)
	        cin>>arr1[i];
	   
	   for(int i=0;i<m;i++)
	        cin>>arr2[i];
	        
	   cout<<canBeSwapped(arr1,arr2)<<endl;
	}
	
	return 0;
}
