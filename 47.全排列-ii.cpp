/*
* @lc app=leetcode.cn id=47 lang=cpp
*
* [47] 全排列 II
*/
// @lc code=start


class Solution {
public:
	vector<int> vis;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
		vector<int> t;
		vector<int> vis(nums.size(), false);
		premute(nums, 0, t, ans, vis);

		return ans;
	}

	void premute(vector<int>& nums, int cur, vector<int>& t, vector<vector<int> >& ans, vector<int>& vis)
	{
		if (cur == nums.size()) 
		{
			ans.push_back(t);
			return;
		}

		for (unsigned i = 0; i < nums.size(); ++i)
		{
			if (vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1])) {
                continue;
            }
            vis[i] = true;
            t.push_back(nums[i]);
            premute(nums, cur + 1, t, ans, vis);
            vis[i] = false;
            t.pop_back();
        }

	}
};

// @lc code=end

