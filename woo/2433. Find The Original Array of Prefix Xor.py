from itertools import pairwise

class Solution:
    def findArray(self, pref):
        return [a ^ b for a, b in pairwise([0] + pref)]
