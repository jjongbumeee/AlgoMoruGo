class Solution(object):
    def averageValue(self, nums):
        nums = [num for num in nums if num % 6 == 0]
        return sum(nums) // len(nums) if nums else 0
