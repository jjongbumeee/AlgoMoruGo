from collections import Counter

class Solution:
    def robotWithString(self, s):
        ret, stack, counter = [], [], Counter(s)
        for c in s:
            stack.append(c)
            counter[c] -= 1
            if counter[c] == 0:
                del counter[c]
            while counter and stack and min(counter) >= stack[-1]:
                ret.append(stack.pop())
        return ''.join(ret + stack[::-1])
