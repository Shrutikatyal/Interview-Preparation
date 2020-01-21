/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Round upto previous power of 2	
 */
 
#include<iostream>
using namespace std;

int prevPowerOf2(unsigned int num){
	
	while(num & num-1)
		num = num & num-1;
	
	return num;
	
}

int main(){
	unsigned int num;
	
	cout<<"Enter a number:";
	cin>>num;
	cout<<"\n"<<num<<" rounds upto "<<prevPowerOf2(num);
	return 0;
}
