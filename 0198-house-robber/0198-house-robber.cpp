class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0, rob2=0;
        for(int num:nums){
            int temp=max(rob2, rob1+num);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
    }
};