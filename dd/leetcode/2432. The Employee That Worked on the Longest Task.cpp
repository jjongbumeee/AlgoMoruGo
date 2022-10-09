class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = 500, t = 0;
        for (int i = logs.size() - 1; i >= 1; --i) {
            int endLeft = logs[i - 1][1];
            int id = logs[i][0];
            int endRight = logs[i][1];

            int amount = endRight - endLeft;
            if (amount > t) {
                t = amount;
                ans = id;
            }
            else if (amount == t) {
                ans = min(ans, id);
            }
        }
        if (logs[0][1] > t) {
            // t = logs[0][1];
            ans = logs[0][0];
        }
        else if (logs[0][1] == t) {
            ans = min(ans, logs[0][0]);
        }
        return ans;
    }
};