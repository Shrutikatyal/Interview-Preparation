/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Round upto next power of 2	
 */
 
#include<iostream>
using namespace std;

int nextPowerOf2(unsigned int num){
	
	num = num-1;
	
	while(num & num-1)
		num = num & num-1;
	
	return num<<1;
	
}

int main(){
	unsigned int num;
	
	cout<<"Enter a number:";
	cin>>num;
	cout<<"\n"<<num<<" rounds upto "<<nextPowerOf2(num);
	return 0;
}
