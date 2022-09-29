// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int mx = 0;
        for (int k : nums) {
            mx = max(mx, k);
        }
        
        int len = 0;
        for (int k : nums) {
            if (mx == k) {
                ++len;
            }
            else {
                len = 0;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};