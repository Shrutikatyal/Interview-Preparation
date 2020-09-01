/*
 * Author : Shruti Katyal
 * Date   : 05 June, 2020
 *
 * Compiler : g++ 5.1.0
 * Flags    : -std=c++14
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       //https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation
       
        int N1 = nums1.size(), N2 = nums2.size();
        
        if(N1 < N2) return findMedianSortedArrays(nums2,nums1);
        
        int low = 0, high = N2;   
        
        while(low <= high){
            int mid2 = (low + high)/2;
            int mid1 = (N1 + N2)/2 - mid2;
            
            int L1 = mid1 == 0? INT_MIN : nums1[mid1-1];
            int L2 = mid2 == 0? INT_MIN : nums2[mid2-1];
            int R1 = mid1 == N1? INT_MAX : nums1[mid1];
            int R2 = mid2 == N2? INT_MAX : nums2[mid2];
                        
            if(L1 > R2)
                low = mid2 + 1;     //Because mid2 badhege tabhi mid1 kam hoga and mid2 tabhi badhege jab low badhege and high constant rhega
            else if(L2 > R1)
                high = mid2 - 1; 
            else 
                return (N1+N2)%2 ? min(R1,R2) : (max(L1,L2) + min(R1,R2))/2.;
                
        }
        return 0;
    }
    
};
