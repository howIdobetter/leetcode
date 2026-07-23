/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<bool> st(128);
        int l = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (st[s[i]]) {
                while (s[l] != s[i]) {
                    st[s[l]] = false;
                    l++;
                }
                l++;
            } else {
                st[s[i]] = true;
                ans = std::max(ans, i - l + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

