/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Find two odd occuring with o(1) space 
 */
 
#include<iostream>
#include<math.h>
using namespace std;

void findOddOccuringPair(int arr[],int n){
	
	int res=0;
	
	for(int i=0;i<n;i++)
		res ^= arr[i];
		
	int pos = log2(res & -res);
	
	int x=0, y=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i] & (1>>pos))
			x = x^arr[i];
		else
			y = y^arr[i];
	}
	
	cout<<"\n"<<x<<" "<<y;
}

int main(){
	int n;
	
	cout<<"\nEnter the size of array:";
	cin>>n;
	
	int arr[n];
	cout<<"\nEnter the array elements:";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	findOddOccuringPair(arr,n);
	return 0;
}
