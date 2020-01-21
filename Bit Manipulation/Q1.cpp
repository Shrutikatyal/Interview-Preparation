/*
 * Author : Shruti Katyal
 * Date   : 17 January, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 * Problem : Check if a given integer is odd or even
 */
 
#include<iostream>
using namespace std;

class Solution{
	private:
		int num;
	public:
		void checkOddEven(){
			if(num & 1)
				cout<<num<<" is odd.";
			else
				cout<<num<<" is even.";
		}
		
		void setInput(int no)
		{
			num = no;
		}
};

int main()
{
	Solution sol;
	int num;
	
	
	cout<<"Enter a number:";
	cin>>num;
	sol.setInput(num);
	
	sol.checkOddEven();
	return 0;
}
