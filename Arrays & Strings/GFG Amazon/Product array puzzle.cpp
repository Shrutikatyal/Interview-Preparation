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

void product(vector<int> nums){
    
    int leftProd = 1;
    vector<int> ans(nums.size());
    
    for(int i=0; i<nums.size(); i++){
        ans[i] = leftProd;
        leftProd *= nums[i];
    }    
    
    int rightProd = 1;
    
    for(int i=nums.size()-1; i>=0; i--){
        ans[i] *= rightProd;
        rightProd *= nums[i];
    }
    
    for(int i=0; i<nums.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
	//code
	int t;
	cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
       product(a);
    }
	return 0;
}
