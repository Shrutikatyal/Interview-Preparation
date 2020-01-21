/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Find parity of the num
 *		odd - 1 	even - 0
 */
 
#include<iostream>
using namespace std;

bool findParity(int num){
	
	bool parity=false;
	while(num)
	{
		parity = !parity;
		num = num & num-1;
	}
	
	return parity;
}

//LookUp table method
bool findParity(int num)
{
	int x = num;
	
	x ^= x>>16;
	x ^= x>>8;
	x ^= x>>4;
	x ^= x>>2;
	x ^= x>>1;
	
	return x&1;
}

int main(){
	int n;
	
	cout<<"Enter a number:";
	cin>>n;

	if(findParity(n))
		cout<<"\n"<< n <<" is of odd parity.";
	else
		cout<<"\n"<< n <<" is of even parity.";
	return 0;
}
