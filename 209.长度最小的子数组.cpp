/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */


// @lc code=start
class Solution {
public:
    // O(n^2)
    // int minSubArrayLen(int s, vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) {
    //         return 0;
    //     }
    //     int ans = INT_MAX;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int sum = 0;
    //         for (int j = i; j < n; j++)
    //         {
    //             sum += nums[j];
    //             if (sum >= s)
    //             {
    //                 ans = min(ans, j - i + 1);
    //                 break;
    //             }
    //         }
    //     }
    //     return ans == INT_MAX ? 0 : ans;
    // }
    
    // O(n): 双指针，其中 n 是数组的长度。指针start和end最多各移动 n 次
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        int MAX_VALUE = INT_MAX;
        int ans = MAX_VALUE;

        int start = 0, end = 0;   // 初始化
        int sum = 0;
        
        while (end < n)
        {
            sum += nums[end];
            while (sum >= s)
            {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;

            }
            end++;
        }
        
        return ans == MAX_VALUE ? 0 : ans;
      
    }

};
// @lc code=end