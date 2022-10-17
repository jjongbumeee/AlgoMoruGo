class Solution(object):
    def countDistinctIntegers(self, nums):
        return len(set([int(str(num)[::-1]) for num in nums] + nums))
