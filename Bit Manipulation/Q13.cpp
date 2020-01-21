/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Uppercase To lowercase
 *			 Invert case
 */
 
#include<iostream>
using namespace std;

char upperToLower(char a){
	
	return a|' ';
}

char lowerToUpper(char a)
{
	return a&'_';
}

char invertCase(char a){	
	return a ^ ' ';
}

int main(){
	char ch;
	
	cout<<"Enter a character:";
	cin>>ch;
	cout<<"\n"<<upperToLower(ch)<<" "<<lowerToUpper(ch);
	cout<<"\n"<<invertCase(ch);
	return 0;
}
