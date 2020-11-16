/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int nlen = nums.size();
        if (nlen == 0) 
        {
            return 0;
        }
        if (nlen == 1)
        {
            return nums[0];
        }
        return max(my_rob(nums, 0, nlen-1), my_rob(nums, 1, nlen));
    }

    int my_rob(vector<int>& nums, int start, int end)
    {
        int cur = 0,  pre = 0;
        for (int i = start; i < end; i++)
        {
            int t = cur;
            cur = max(pre + nums[i], cur);
            pre = t;
        }
        return cur;
    }
};
// @lc code=end

