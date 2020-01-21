/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Turn off k-th bit
 */
 
#include<iostream>
#include<bitset>
using namespace std;

int turnOffKBit(int num, int k){
	
	int mask = ~(1<<(k-1));
	return num & mask;
}

int main(){
	int n,k;
	
	cout<<"Enter n and k respectively:";
	cin>>n>>k;
	
	cout << n << " in binary is " << bitset<8>(n) << endl;
	cout << "Turning k'th bit off\n";
	n = turnOffKBit(n,k);
	cout << n << " in binary is " << bitset<8>(n) << endl;
	
	
	return 0;
}
