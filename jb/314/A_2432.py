class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        # pos = 0
        maxDuration = maxId = pos = 0
        for (id, leaveTime) in logs:
            duration = leaveTime - pos
            if duration > maxDuration:
                maxDuration = duration
                maxId = id
            elif duration == maxDuration:
                maxId = min(maxId, id)
            pos = leaveTime
        return maxId
