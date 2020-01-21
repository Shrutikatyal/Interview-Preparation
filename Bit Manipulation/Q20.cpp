/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Power of 4
 */
 
#include<iostream>
using namespace std;

bool powerOf4(unsigned int num){
	
	//AAAAAAAA = 1010 1010 1010 1010 1010 1010 1010 1010
	//check if num is a power of 2 and is it an even power or not?
	
	return num && !(num & num-1) && !(num & 0xAAAAAAAA);
}

int main(){
	unsigned int num;
	
	cout<<"Enter a number:";
	cin>>num;
	cout<<"\n Is "<<num<<" a power of 4? "<<powerOf4(num);
	return 0;
}
