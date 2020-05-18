/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
#include <iostream>
using namespace std;

int minEnergy(int arr[], int n){
    
    int min = 0;
    int curr = 0;
    
    for(int i=0; i<n; i++){
        curr += arr[i];
        
        if(curr <= 0){
            min += abs(curr)+1;
            curr = 1;   //(Because remaining current is 1)
            
        }
    }
    
    if(min==0)
        return 1;
    return min;
}

int main() {
	//code
	int T;
	cin>>T;
	
	while(T--){
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	   
	   cout<<minEnergy(arr,n)<<endl;
	}
	return 0;
}
