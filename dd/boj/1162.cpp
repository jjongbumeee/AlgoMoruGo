// https://www.acmicpc.net/problem/1162
#include <iostream>
#include <queue>
using namespace std;

using LL = long long;
const LL INF = 49999000000;
const int MAX_NODE = 10001;

struct Node {
    int dest;
    LL cost;
    int k;
    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
};

int N, M, K;
LL dist[21][MAX_NODE];
vector<Node> adj[MAX_NODE];

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({ v,t });
        adj[v].push_back({ u,t });
    }
}

void solution() {
    for (int k = 0; k <= K; ++k) {
        for (int i = 1; i <= N; ++i) {
            dist[k][i] = INF;
        }
    }
    LL ans = INF;
    priority_queue<Node> pq;
    dist[K][1] = 0;
    pq.push({ 1, 0, K });
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        if (now.dest == N) {
            if (ans > now.cost) ans = now.cost;
        }
        if (now.cost > dist[now.k][now.dest]) continue;
        for (Node& next : adj[now.dest]) {
            if (dist[now.k][next.dest] > next.cost + now.cost) {
                dist[now.k][next.dest] = next.cost + now.cost;
                pq.push({ next.dest, dist[now.k][next.dest], now.k });
            }
            if (now.k > 0) {
                if (dist[now.k - 1][next.dest] > 0 + now.cost) {
                    dist[now.k - 1][next.dest] = 0 + now.cost;
                    pq.push({ next.dest, dist[now.k - 1][next.dest], now.k - 1 });
                }
            }
        }
    }
    cout << ans;
}

int main() {
    input();
    solution();
    return 0;
}