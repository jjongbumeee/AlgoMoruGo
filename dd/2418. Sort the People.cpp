// https://leetcode.com/problems/sort-the-people/

class Solution {
    struct _data {
        string name;
        int height;
        
        bool operator<(const _data& other) const {
            return height > other.height;
        }
    };
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<_data> v;
        for (int i = 0; i < names.size(); ++i) {
            v.push_back({ names[i], heights[i] });
        }
        sort(v.begin(), v.end());
        vector<string> ans;
        for (auto& t : v) {
            ans.push_back(t.name);
        }
        return ans;
    }
};