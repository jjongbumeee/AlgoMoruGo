class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> us;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            string str = to_string(nums[i]);
            reverse(str.begin(), str.end());
            int k = stoi(str);
            nums.push_back(k);
            us.insert(nums[i]);
            us.insert(k);
        }
        return (int)us.size();
    }
};