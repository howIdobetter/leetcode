/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
private:
    using pii = pair<int, int>;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        if (!n) return 0;
        int res = 0;
        if (check(grid, m, n)) return res;
        while (1) {
            int t = demon(grid, m, n);
            res++;
            bool flag = check(grid, m, n);
            if (t == 0 && !flag) return -1;
            if (flag) break;
        }
        return res;
    }
    int demon(vector<vector<int>>& grid, int m, int n) {
        int op = 0;
        vector<pii> bad;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) bad.push_back({i, j});
            }
        }
        for (auto [x, y] : bad) {
            for (int k = 0; k < 4; k++) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (grid[xx][yy] == 1) {
                    grid[xx][yy] = 2;
                    op++;
                }
            }
        }
        return op;
    }
    bool check(vector<vector<int>>& grid, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return false;
            }
        }
        return true;
    }
};
// @lc code=end

