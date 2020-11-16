#
# @lc app=leetcode.cn id=209 lang=python3
#
# [209] 长度最小的子数组
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0

        INT_MAX = 999999999
        ans = INT_MAX
        start = end = 0
        sums = 0 
        while end < n:
            sums += nums[end]
            while sums >= s:
                ans = min(ans, end - start + 1)
                sums -= nums[start]
                start += 1
            end += 1
        ans = 0 if ans == INT_MAX else ans
        
        return ans 
# @lc code=end

