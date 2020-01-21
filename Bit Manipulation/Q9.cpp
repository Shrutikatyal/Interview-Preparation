/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Power of 2
 */
 
#include<iostream>
using namespace std;

bool isPowerOf2(int num){
	return !(num & num-1);
}

int main(){
	int n;
	
	cout<<"Enter a number:";
	cin>>n;
		
	if(isPowerOf2(n))
		cout<<"\n"<< n <<" is a power of 2.";
	else
		cout<<"\n"<< n <<" is not a power of 2.";
	return 0;
}
