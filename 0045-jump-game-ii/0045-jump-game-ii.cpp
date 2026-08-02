class Solution {
public:
    int jump(vector<int>& nums) {
        int j=0, current=0, farthest=0;
        for(int i=0; i<nums.size()-1; i++){
            farthest=max(farthest, i+nums[i]);
            if(i==current){
                j++;
                current=farthest;
                if(current>=nums.size()-1) break;
            }
        }
        return j;
    }
};