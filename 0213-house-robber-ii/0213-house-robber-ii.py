class Solution:
    def rob(self, nums: list[int]) -> int:
        if not nums:
            return 0
        if len(nums)==1:
            return nums[0]
        def rob_linear(houses:list[int])->int:
            rob1, rob2=0,0
            for n in houses:
                new_rob=max(rob1+n, rob2)
                rob1=rob2
                rob2=new_rob
            return rob2
        return max(rob_linear(nums[:-1]),rob_linear(nums[1:]))
        