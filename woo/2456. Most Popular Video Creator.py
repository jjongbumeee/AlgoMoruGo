class Solution(object):
    def mostPopularCreator(self, creators, ids, views):
        users = {creator: [[0, '']] for creator in creators}
        for creator, video_id, view in zip(creators, ids, views):
            users[creator][0][0] -= view
            users[creator].append([-view, video_id])
        max_view = min(map(lambda x: x[0][0], users.values()))
        history = [history for history in users.items() if history[-1][0][0] == max_view]
        return [[name, sorted(videos)[1][1]] for name, videos in history]
