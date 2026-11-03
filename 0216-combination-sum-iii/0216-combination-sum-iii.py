class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        results=[]
        def backtrack(start: int, current_combination: list[int], remaining_sum:int):
            if len(current_combination)==k:
                if remaining_sum==0:
                    results.append(list(current_combination))
                return
            if remaining_sum<0:
                return
            for num in range (start, 10):
                if num>remaining_sum:
                    break
                current_combination.append(num)
                backtrack(num+1, current_combination,remaining_sum-num)
                current_combination.pop()
        backtrack(1,[],n)
        return results
        