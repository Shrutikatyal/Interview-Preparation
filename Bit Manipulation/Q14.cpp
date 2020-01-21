/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Absolute of a number
 			num>>31 will give -1 for -ve numbers and 0 for positive
 			~num>>31 will give 0 for -ve numbers and -1 for positive
 				
 */
 
#include<iostream>
using namespace std;

int abs(int num){
	
//	if(num<0)
//		return (num - 1) ^ -1; 

	//without branching
	return (((num>>31) & (~num+1))| ((~num>>31) & num));
}

int main(){
	int n;
	
	cout<<"Enter a number:";
	cin>>n;

	cout<<"\n Absolut of "<< n <<": "<<abs(n);
	return 0;
}
