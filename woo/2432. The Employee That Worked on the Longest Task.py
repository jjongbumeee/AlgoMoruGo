class Solution(object):
    def hardestWorker(self, n, logs):
        prev, ret = 0, (0, 0)
        for _id, curr in logs:
            ret = min(ret, (prev - curr, _id))
            prev = curr
        return ret[1]
