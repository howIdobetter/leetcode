/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) {
            return 0;
        }
        std::vector<int> left_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = std::max(left_max[i - 1], height[i]);
        }
        std::vector<int> right_max(n);
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = std::max(right_max[i + 1], height[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += std::min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};
// @lc code=end

