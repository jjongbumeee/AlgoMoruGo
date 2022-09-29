class Solution(object):
    def sortPeople(self, names, heights):
        temp = zip(names,heights)
        temp.sort(key=lambda x: x[1], reverse=True)
        return [str(x[0]) for x in temp]
