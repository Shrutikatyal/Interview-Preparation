/*
 * Author : Shruti Katyal
 * Date   : 17 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
 
// { Driver Code Starts
#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends


// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k

struct myCompare{
    bool operator()(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }        
};

int *mergeKArrays(int arr[][N], int k)
{
//code here
    //vector<int> mat;
    vector<int> mat;
    int j = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, myCompare> pq;
    
    for(int i=0; i < k; i++)
        pq.push( { arr[i][0], i, 0} );
    
    
    while(!pq.empty()){
        vector<int> elt = pq.top();
        pq.pop();
    
        mat.push_back(elt[0]);
        cout<<mat.back()<<" ";
        
        if(elt[2] < k-1)
            pq.push( {arr[elt[1]][elt[2]+1], elt[1], elt[2]+1} );
    }    
    
    cout<<endl;
    
    return &mat[0];
}
