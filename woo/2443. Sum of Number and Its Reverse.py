class Solution(object):
    def sumOfNumberAndReverse(self, num):
        return any(int(str(i)[::-1]) + i == num for i in range(num + 1))
