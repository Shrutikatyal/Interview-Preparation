/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Palindrome	
 */

#include <iostream>
#include<bitset>
using namespace std;

// return true if binary representation of n is a palindrome
bool isPalindrome(unsigned n)
{
	// rev stores reverse of binary representation of n
	unsigned rev = 0;
	
	// do till all bits of n are processed
	unsigned k = n;
	while (k)
	{
		// add rightmost bit to rev something like n = 2*n+(0 or 1)
		rev = (rev << 1) | (k & 1);
		cout<<bitset<8>(rev)<<" "<<bitset<8>(k)<<"\n";
		k = k >> 1;		// drop last bit
		cout<<bitset<8>(k)<<"\n\n";

	}

	// return true if reverse(n) is same as n
	return n == rev;
}

int main() 
{
	int n = 0;	// 1001

	cout<<"Enter a number:";
	cin>>n;
	
	if (isPalindrome(n))
		cout << n << " is Palindrome";
	else
		cout << n << " is not a Palindrome";


	return 0;
}
