/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Detect if two numbers have opposite signs
 */
 
#include<iostream>
using namespace std;

bool hasOppositeSigns(int num1, int num2){
	return (num1 ^ num2) < 0;
}

int main(){
	int a,b;
	
	cout<<"Enter two numbers:";
	cin>>a>>b;
	
	if(hasOppositeSigns(a,b))
		cout<<a<<" "<<b<<" are of different signs.";
	else
		cout<<a<<" "<<b<<" are of same sign.";
		
	return 0;
}
