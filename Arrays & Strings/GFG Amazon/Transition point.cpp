/*
 * Author : Shruti Katyal
 * Date   : 16 May, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */

// Function to find the transition point
int transitionPoint(int arr[], int n) {
    // code here
    int low=0, high = n-1;
    
    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(arr[mid]==1 && (mid==low || arr[mid-1]==0))
            return mid;
        else if(arr[mid]< 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;
}
