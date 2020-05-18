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

void calcSpan(vector<short> stocks){
    
    vector<short> span(stocks.size());
    span[0] = 1;
    cout<<span[0]<<" ";
    
    for(short i=1; i < stocks.size(); i++){
        int count = 1;
        while((i-count) >= 0 && stocks[i] >= stocks[i-count])
            count += span[i-count];
        span[i] = count;
        cout<<span[i]<<" ";
    }
    
    cout<<endl;
}

int main() {
	//code
	
	short T;
	cin>>T;
	
	while(T--){
	    short n;
	    cin>>n;
	    
	    vector<short> prices(n);
	    
	    for(short i=0; i<n; i++)
	        cin>>prices[i];
	    
	    calcSpan(prices);
	}
	
	return 0;
}
