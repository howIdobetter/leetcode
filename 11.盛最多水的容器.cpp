/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0, p2 = height.size() - 1;
        int res = 0;
        while (p1 < p2) {
            if (height[p1] < height[p2]) {
                res = std::max(res, (p2 - p1) * height[p1]);
                p1++;
            } else {
                res = std::max(res, (p2 - p1) * height[p2]);
                p2--;
            }
        }
        return res;
    }
};
// @lc code=end

