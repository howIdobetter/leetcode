/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    using pii = std::pair<int, int>;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> result(m * n, 0);
        int idx = 0;
        pii a1 = {0, 0}, a2 = {0, n - 1}, a3 = {m - 1, n - 1}, a4 = {m - 1, 0};
        while (a1.first <= a4.first && a1.second <= a2.second) {
            for (int i = a1.second; i <= a2.second; i++) {
                result[idx++] = matrix[a1.first][i];
            }
            for (int i = a2.first + 1; i <= a3.first; i++) {
                result[idx++] = matrix[i][a2.second];
            }
            if (a1.first == a4.first || a1.second == a2.second) {
                break;
            }
            for (int i = a3.second - 1; i >= a4.second; i--) {
                result[idx++] = matrix[a3.first][i];
            }
            for (int i = a4.first - 1; i > a1.first; i--) {
                result[idx++] = matrix[i][a4.second];
            }
            a1.first++, a1.second++;
            a2.first++, a2.second--;
            a3.first--, a3.second--;
            a4.first--, a4.second++;
        }
        return result;
    }
};
// @lc code=end

