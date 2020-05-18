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

int countBuildings(vector<int> heights){
    
    int prev = -1;
    int count = 0;
    
    for(int i=0; i<heights.size(); i++){
        if(heights[i] > prev){
            prev = heights[i];
            count++;
        }
    }
    
    return count;
    
}

int main() {
	//code
	int t;
	cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
       cout<<countBuildings(heights)<<endl;
    }
	return 0;
}
