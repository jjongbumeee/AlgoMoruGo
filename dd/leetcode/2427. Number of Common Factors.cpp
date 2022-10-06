class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        if (a < b) swap(a, b);
        for (int i = 1; i <= b; ++i) {
            if (a % i == 0 && b % i == 0) ++ans;
        }
        return ans;
    }
};