/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Set k-th bit
 */
 
#include<iostream>
#include<bitset>
using namespace std;

int turnOnKBit(int num, int k){

	int mask = (1<<(k-1));
	return num | mask;
}

int main(){
	int n,k;
	
	cout<<"Enter n and k respectively:";
	cin>>n>>k;
	
	cout << n << " in binary is " << bitset<sizeof(int)*8>(n) << endl;
	cout << "\nTurning k'th bit off\n";
	n = turnOnKBit(n,k);
	cout << n << " in binary is " << bitset<sizeof(int)*8>(n) << endl;
	
	return 0;
}
