class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far=0;
        int target=nums.size()-1;
        for(int i=0; i<nums.size(); ++i){
            if(i>far){
                return false;
            }
            far=max(far,i+nums[i]);
            if(far>=target){
                return true;
            }
        }
        return far>=target;
    }
};