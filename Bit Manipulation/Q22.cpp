/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Swap adjacent bits	
 */
 
#include<iostream>
#include<bitset>
using namespace std;

int swapAdjBits(int num){
	
	int evenBits = (num & 0xAAAAAAAA)>>1;
	int oddBits  = (num & 0x55555555)<<1;
	
	return evenBits | oddBits;
	
}

int main(){
	int num;
	
	cout<<"Enter a number:";
	cin>>num;
	
	cout<<"\n\n"<<num<<" before swapping :"<<bitset<32>(num);
	cout<<"\n"<<num<<" after swapping  :"<<bitset<32>(swapAdjBits(num));
	return 0;
}
