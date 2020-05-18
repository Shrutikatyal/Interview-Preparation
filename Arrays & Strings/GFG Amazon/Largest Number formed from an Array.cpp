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

int myCompare(string X, string Y){
    string XY = X.append(Y); 
  
    string YX = Y.append(X); 
    
    return XY.compare(YX) > 0 ? 1: 0;
}

void printLargest(vector<string> arr) 
{ 
    sort(arr.begin(), arr.end(), myCompare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i];
    cout<<endl;
} 

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    
	    vector<string> nums(n);
	    for(int i=0; i<n; i++)
	        cin>>nums[i];
	        
	    printLargest(nums);     
	}
	return 0;
}
