#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        slen = len(s)
        if slen < 2:
            return s 
        
        maxLen = 1
        begin = 0
        dp = [[True] * slen for _ in range(slen)]

        for j in range(slen):
            for i in range(0, j):
                if s[i] != s[j]:
                    dp[i][j] = False
                else:
                    if j - i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i + 1][j - 1]

                if dp[i][j] and j - i + 1 > maxLen:
                    maxLen = j - i + 1
                    begin = i
            
        return s[begin:begin+maxLen]


# @lc code=end

