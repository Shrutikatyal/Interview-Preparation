/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Check rightmost set bit
 */
 
#include<iostream>
using namespace std;

int rightMostSetBit(int num){
	
	return (num & num-1)^num;
}

int main(){
	int n;
	
	cout<<"Enter a number:";
	cin>>n;
	
	cout<<"\n"<< rightMostSetBit(n) <<" is the rightmost set bit.";
	
	return 0;
}
