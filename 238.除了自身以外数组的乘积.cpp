/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除了自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return {};
        std::vector<int> p_mu(n);
        std::vector<int> h_mu(n);
        p_mu[0] = nums[0];
        for (int i = 1; i < n; i++) {
            p_mu[i] = p_mu[i - 1] * nums[i];
        }
        h_mu[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            h_mu[i] = h_mu[i + 1] * nums[i];
        }
        std::vector<int> result;
        result.push_back(h_mu[1]);
        for (int i = 1; i <= n - 2; i++) {
            result.push_back(p_mu[i - 1] * h_mu[i + 1]);
        }
        result.push_back(p_mu[n - 2]);
        return result;
    }
};
// @lc code=end

