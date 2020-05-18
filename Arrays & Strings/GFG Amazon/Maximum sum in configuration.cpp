/*
 * Author : Shruti Katyal
 * Date   : 18 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here

    int total = 0;
    for(int i=0; i<N; i++)
        total += A[i];
        
    int curr_val = 0;
    int max_val;
    
    for(int i=0; i<N; i++)
        curr_val += i*A[i];
        
    max_val = curr_val;    
    
    for(int i=1; i<N; i++){
        //Left rotate
        //Why add A[i-1]*N and not A[i-1]*(N-1)?
        /*Because when we subtract total sum in the prev curr_val A[i-1] 
        contributed 0. However we have minused its share as well so to 
        balance it add A[i-1] and for the next_val its share is A[i-1]*(n-1)*/
        curr_val = curr_val - total + A[i-1]*N;
        max_val = max(curr_val,max_val);
    }
    
    return max_val;
}
