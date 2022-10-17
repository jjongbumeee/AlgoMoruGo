class Solution(object):
    def findMaxK(self, nums):
        ret = -1
        used = set()
        for num in nums:
            if -num in used:
                ret = max(ret, abs(num))
            used.add(num)
        return ret
