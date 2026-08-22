class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int minIdx=0;
        int maxIdx=0;
        for(int i=1; i<n;i++){
            if(nums[i]<nums[minIdx]) minIdx=i;
            if(nums[i]>nums[maxIdx]) maxIdx=i;
        }
        int low=min(minIdx, maxIdx);
        int high=max(minIdx, maxIdx);
        int front=high+1, back=n-low, both=(low+1)+(n-high);
        return min({front,back,both});
    }
};