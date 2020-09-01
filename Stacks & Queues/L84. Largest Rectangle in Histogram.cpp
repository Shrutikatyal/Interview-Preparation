class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()< 1) return 0;
        vector<int> left(heights.size(),0), right(heights.size(),0); //Nearest left rectangle with smaller height
        left[0] = -1;
        
        for(int i=1; i<heights.size();i++){
            int j = i-1;
            while(j>=0 && heights[j]>=heights[i])
                j = left[j];
            left[i] = j;
        }
        
        right[heights.size()-1] = heights.size();
        
        for(int i=heights.size()-2;i>=0;i--){
            
            int j = i + 1;
            while(j < heights.size() && heights[j] >= heights[i])
                j = right[j];
            right[i] = j;
        }
        
        int area = 0;
        
        for(int i=0;i<heights.size();i++)
            area = max(area, (right[i]-left[i]-1)*heights[i]);
        
        return area;
    }
};
