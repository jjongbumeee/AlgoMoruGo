from collections import defaultdict


class Solution(object):
    def numberOfPaths(self, grid, k):
        MOD = 10 ** 9 + 7
        grid = [[0] * (len(grid[0]) + 1)] + [[0] + row for row in grid]
        dp = [[defaultdict(int) for _ in range(len(grid[0]))] for _ in range(len(grid))]
        dp[1][1][grid[1][1] % k] = 1
        for x in range(1, len(grid)):
            for y in range(1, len(grid[0])):
                for key, value in dp[x - 1][y].items():
                    dp[x][y][(key + grid[x][y]) % k] += value % MOD
                for key, value in dp[x][y - 1].items():
                    dp[x][y][(key + grid[x][y]) % k] += value % MOD
        return dp[-1][-1][0] % MOD
