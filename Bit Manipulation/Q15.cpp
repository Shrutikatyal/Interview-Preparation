/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Number of bits to be flipped	
 */
 
#include<iostream>
using namespace std;

int countFlipBits(int num1,int num2){
	num1 = num1 ^ num2;
	int count=0;
	while(num1)
	{
		count++;
		num1 = num1 & num1-1;
	}
	return count;
}

int main(){
	int num1,num2;
	
	cout<<"Enter two numbers:";
	cin>>num1>>num2;

	cout<<"Number of bits to be flipped:"<<countFlipBits(num1,num2);
	return 0;
}
