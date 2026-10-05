class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=nums[0];
        int curr_max=nums[0];
        int curr_min=nums[0];
        for(size_t i=1; i<nums.size(); ++i){
            int n=nums[i];
            if(n<0){
                swap(curr_max, curr_min);
            }
            curr_max=max(n,n*curr_max);
            curr_min=min(n,n*curr_min);
            res=max(res, curr_max);
        }
        return res;
    }
};