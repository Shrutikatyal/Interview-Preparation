/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Max and min without branching	
 */
 
#include<iostream>
using namespace std;

void findMaxMin(int num1,int num2){
	
	cout<<"\n\nMinimum of two is"<<(num1^((num1^num2) & -(num1>num2)));
	cout<<"\n\nMaximum of two is"<<(num1^((num1^num2) & -(num1<num2)));
	
}

int main(){
	int num1,num2;
	
	cout<<"Enter two numbers:";
	cin>>num1>>num2;

	findMaxMin(num1,num2);
	return 0;
}
