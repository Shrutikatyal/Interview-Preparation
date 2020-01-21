/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Swap two numbers without using third variable
 *	a = a^b
 *	b = a^b
 *	a = a^b
 */
 
#include<iostream>
using namespace std;

void swap(int &num1, int &num2){
	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;
}

int main(){
	int num1,num2;
	
	cout<<"Enter two numbers:";
	cin>>num1>>num2;
	
	cout<<"\n Before swapping:\n     num1:"<<num1<<"     num2:"<<num2;
	swap(num1,num2);
	cout<<"\n\n After swapping:\n     num1:"<<num1<<"     num2:"<<num2;
		
	return 0;
}
