/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        while (1) {
            while (p1 < nums.size() && nums[p1] != 0) p1++;
            while (p2 < nums.size() && nums[p2] == 0) p2++;
            if (p1 >= nums.size() || p2 >= nums.size()) break;
            if (p1 > p2) p2 = p1 + 1;
            else {
                std::swap(nums[p1], nums[p2]);
            }
        }
    }
};
// @lc code=end

