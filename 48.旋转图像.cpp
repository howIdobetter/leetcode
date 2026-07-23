/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return;
        int n = matrix.size();
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int another = 0;
        while (left < right) {
            for (int i = 0; i < right - left; i++) {
                int temp = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = temp;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
    }
};
// @lc code=end

