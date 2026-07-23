/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s;
        int maxcount = 0;
        for (auto num : nums) {
            s.insert(num);
        }
        for (auto num : s) {
            if (s.find(num - 1) != s.end()) continue;
            int count = 1;
            int cur = num;
            while (s.find(cur + 1) != s.end()) {
                cur++;
                count++;
            }
            maxcount = std::max(count, maxcount);
        }
        return maxcount;
    }
};
// @lc code=end

