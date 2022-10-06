class Solution {
    static constexpr int dr[] = { -1, -1, -1, 0, 1, 1, 1 };
    static constexpr int dc[] = { -1, 0, 1, 0, -1, 0, 1 };
    
    int m; // row
    int n; // column
    
    inline bool isRange(const int& r, const int& c) const {
        return 0 <= r && r < m && 0 <= c && c < n;
    }
    
public:
    int maxSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int r = 1; r < m - 1; ++r) {
            for (int c = 1; c < n - 1; ++c) {
                int candSum = 0;
                for (int d = 0; d != 7; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (!isRange(nr, nc)) continue;
                    candSum += grid[nr][nc];
                }
                ans = ans > candSum ? ans : candSum;
            }
        }
        return ans;
    }
};