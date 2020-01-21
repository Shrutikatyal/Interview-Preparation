/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Check if kth bit is set or not
 */
 
#include<iostream>
#include<bitset>
using namespace std;

bool checkKthBit(int num, int k){

	int mask = (1<<(k-1));
	return num & mask;
}

int main(){
	int n,k;
	
	cout<<"Enter n and k respectively:";
	cin>>n>>k;
	
	cout<<"\n"<< n << " in binary is " << bitset<sizeof(int)*8>(n) << '\n';
	
	if(checkKthBit(n,k))
		cout<< k <<"th bit is set.";
	else
		cout<< k <<"th bit is not set.";
	return 0;
}
