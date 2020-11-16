#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 贪心算法
        nlen = len(nums)
        # if not nums:
        #     return float("-inf")

        # cur_sum = max_sum = nums[0]
        # for i in range(1, nlen):
        #     cur_sum = max(nums[i], cur_sum + nums[i])
        #     max_sum = max(cur_sum, max_sum)

        # return max_sum

        # 动态规划
        for i in range(1, nlen):
            if nums[i - 1] > 0:
                nums[i] += nums[i - 1]
        
        return max(nums)

# @lc code=end

