/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> result;
        int n = intervals.size();
        if (n < 1) return {};
        std::sort(intervals.begin(), intervals.end());
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] > right) {
                result.emplace_back(std::vector<int>({left, right}));
                left = intervals[i][0];
                right = intervals[i][1];
            } else if (intervals[i][1] > right) {
                right = intervals[i][1];
            }
        }
        result.emplace_back(std::vector<int>({left, right}));
        return result;
    }
};
// @lc code=end

