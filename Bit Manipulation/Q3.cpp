/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Add 1 to given number
 * Approach : 
 *		Negative number is represented as 2's complement of its positive form
 *		-x = ~x + 1
 *		x + 1 = -(~x)
 */
 
#include<iostream>
using namespace std;

int nextNumber(int num){
	return -(~num);
}

int main(){
	int n;
	
	cout<<"Enter a number:";
	cin>>n;
	
	cout<<nextNumber(n);
		
	return 0;
}
