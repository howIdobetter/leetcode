/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> m;
        for (std::string &s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            m[std::move(key)].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        for (auto &p : m) {
            result.push_back(std::move(p.second));
        }
        return result;
    }
};
// @lc code=end

