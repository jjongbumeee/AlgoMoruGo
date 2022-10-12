class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        ret = []
        now = 0
        for idx in range(len(pref)):
            if idx == 0 :
                ret.append(pref[idx])
                now = pref[idx]
            else:
                # print(now, pref[idx], now ^ pref[idx])
                res = now ^ pref[idx]
                ret.append(res)
                now = pref[idx]
        return ret
