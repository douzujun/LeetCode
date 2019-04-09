#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	
    	if (nums.empty()) return 0;
    	int first = 0;
		
		for (unsigned i = 0; i < nums.size(); i++)
		{
			first = first ^ nums[i];   // A ^ B ^ A = B 
		}
		
		return first;
        
    }
};
int main()
{
	vector<int> nums = {4, 1, 2, 1, 2};
	Solution s; 
	int ans = s.singleNumber(nums);
	
	cout << ans << endl;
//	for (const auto& e : nums) {
//		cout << e << " ";
//	}
	cout << endl;
	
	return 0;
}
















