/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> need, window;
        int start = 0, min_len = INT_MAX;
        int valid = 0, left = 0, right = 0;
        int m = s.size(), n = t.size();
        for (char c : t) {
            need[c]++;
        }
        while (right < m) {
            char c = s[right];
            right++;
            if (!need.count(c)) continue;
            window[c]++;
            if (window[c] == need[c]) valid++;
            while (valid == need.size()) {
                if (right - left < min_len) {
                    min_len = right - left;
                    start = left;
                }
                char d = s[left];
                left++;
                if (!need.count(d)) continue;
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
// @lc code=end

