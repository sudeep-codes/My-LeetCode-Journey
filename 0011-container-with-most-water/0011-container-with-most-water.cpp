class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxWater=0;
        while(l<r){
            int currentArea=min(height[l], height[r])*(r-l);
            maxWater=max(maxWater, currentArea);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxWater;
    }
};