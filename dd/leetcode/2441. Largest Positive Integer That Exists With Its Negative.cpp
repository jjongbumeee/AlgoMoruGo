class Solution {
    struct _data {
        bool isNe;
        bool isPo;
    };
public:
    int findMaxK(vector<int>& nums) {
        const int OFFSET = 1000;
        
        int maxK = -1;
        vector<_data> check(1005);
        for (int k : nums) {
            int idxK = k < 0 ? -k : k;
            
            // -30, -30 음수만 입력된 경우에 정답으로 처리하지 않아야 한다.
            if (k < 0) {
                check[idxK].isNe = true;
            }
            else {
                // is not zero
                check[idxK].isPo = true;
            }
            
            if (check[idxK].isNe && check[idxK].isPo) {
                maxK = max(maxK, idxK);
            }
        }
        return maxK;
    }
};