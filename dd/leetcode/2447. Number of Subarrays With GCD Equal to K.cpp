class Solution {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int gcdResult = 0;
            for (int j = i; j < nums.size(); ++j) {
                gcdResult = gcd(nums[j], gcdResult);
                if (gcdResult == k) ++ans;
            }
        }
        return ans;
    }
};