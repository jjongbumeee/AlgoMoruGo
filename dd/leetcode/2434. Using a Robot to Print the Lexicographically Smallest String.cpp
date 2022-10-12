class Solution {
    bool isRemainSmallChar(const int* p, const char& c) {
        int limit = c - 'a';
        for (int i = 0; i < limit; ++i) {
            if (p[i] != 0) return true;
        }
        return false;
    }
public:
    string robotWithString(string s) {
        char stk[100001];
        int alpCnt[26]{0}, top = -1;
        for (char c : s) {
            ++alpCnt[c - 'a'];
        }
        string ans;
        for (const char c : s) {
            --alpCnt[c - 'a'];
            stk[++top] = c;
            while (top >= 0) {
                if (isRemainSmallChar(alpCnt, stk[top])) {
                    break;
                }
                else {
                    ans += stk[top--];
                }
            }
        }
        return ans;
    }
};