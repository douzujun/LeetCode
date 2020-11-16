#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        a = 1
        b = 2
        ans = 0
        for i in range(n-2):
            ans = a + b 
            a = b 
            b = ans 
        return ans
        
# @lc code=end

