/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        if (s_len < p_len) return {};
        std::vector<int> result;
        std::vector<int> count(26);
        for (int i = 0; i < p_len; i++) {
            count[s[i] - 'a']++;
            count[p[i] - 'a']--;
        }
        int differ = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                ++differ;
            }
        }
        if (!differ) {
            result.emplace_back(0);
        }
        for (int i = p_len; i < s_len; i++) {
            if (count[s[i] - 'a'] == -1) {
                differ--;
            } else if (count[s[i] - 'a'] == 0) {
                differ++;
            }
            count[s[i] - 'a']++;
            if (count[s[i - p_len] - 'a'] == 1) {
                differ--;
            } else if (count[s[i - p_len] - 'a'] == 0) {
                differ++;
            }
            count[s[i - p_len] - 'a']--;
            if (!differ) {
                result.emplace_back(i - p_len + 1);
            }
        }
        return result;
    }
};
// @lc code=end

