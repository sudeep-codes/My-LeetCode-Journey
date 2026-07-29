class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto range=equal_range(nums.begin(), nums.end(), target);
        if(range.first==range.second||*range.first!=target){
            return {-1,-1};
        }
        int first=distance(nums.begin(), range.first);
        int last=distance(nums.begin(), range.second)-1;
        return {first, last};
    }
};