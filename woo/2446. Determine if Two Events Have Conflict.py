class Solution(object):
    def haveConflict(self, event1, event2):
        convert = lambda x: int(x.split(':')[0]) * 60 + int(x.split(':')[1])
        return set(range(convert(event1[0]), convert(event1[1]) + 1)) & set(range(convert(event2[0]), convert(event2[1]) + 1))
        
