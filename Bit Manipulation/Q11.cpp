/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Position of only set bit 
 */
 
#include<iostream>
#include<math.h>
using namespace std;

int posOfOnlySetBit(int num){
	if(num & num-1)
		return 0;
	return log2(num)+1;
}

int main(){
	int n;
	
	cout<<"Enter a number:";
	cin>>n;
	
	int pos = posOfOnlySetBit(n);
	if(pos)
		cout<<"\n"<< pos <<" is the only set bit.";
	else
		cout<<"\nInvalid inpuut: Multiple set bits present.";
	return 0;
}
