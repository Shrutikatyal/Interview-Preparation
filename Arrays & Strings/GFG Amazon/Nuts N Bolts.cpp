#include <iostream>
using namespace std;

int partition(char A[], int low, int high,char pivot);

void matchPairs(char nuts[], char bolts[],int low, int high){
    
    if(low < high){
        
		//Sort a nut according to bolt
        int pos = partition(nuts,low,high,bolts[high]); 
        
        for(int i=low; i<=high; i++)
	        cout<<nuts[i]<<" ";
		cout<<endl;
        
        //Sort that bolt according to the nut just settled
        pos = partition(bolts,low,high,nuts[pos]);
        
        matchPairs(nuts,bolts,low,pos-1);
        matchPairs(nuts,bolts,pos+1,high);
        
    }
    
}

int partition(char arr[], int low, int high,char pivot){
	int i = low;  
    for (int j = low; j < high; j++) 
    { 
        if (arr[j] < pivot){ 
        	char temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
            i++; 
        } else if(arr[j] == pivot){
		 
            char temp = arr[j]; 
            arr[j] = arr[high]; 
            arr[high] = temp1; 
            j--; 
        } 
    } 
    
	char temp = arr[i]; 
    arr[i] = arr[high]; 
    arr[high] = temp; 


    return i; 
}

int main() {
	//code
	int T;
	cin>>T;
	
	while(T--){
	    int n;
	    cin>>n;
	    
	    char nuts[n];
	    char bolts[n];
	    
	    for(int i=0; i<n; i++)
	        cin>>nuts[i];
	        
	    for(int i=0; i<n; i++)
	        cin>>bolts[i];
	        
	    matchPairs(nuts,bolts,0,n-1);
	    
	    for(int i=0; i<n; i++)
	        cout<<nuts[i]<<" ";
	    cout<<endl;
	    
	    for(int i=0; i<n; i++)
	        cout<<bolts[i]<<" ";
	    cout<<endl;
	}
	
	return 0;
}
