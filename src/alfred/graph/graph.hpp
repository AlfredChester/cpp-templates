#ifndef ALGR_GRAPH
#define ALGR_GRAPH

#include <bits/stdc++.h>

struct NT {}; // null_type
template <class W = NT>
class Graph {
private:
    struct Edge {
        int to;
        W w;
    };
    std::vector<std::vector<Edge>> G; // (to, E)

public:
    Graph(void) {}
    Graph(int n) : G(n + 1) {}
    inline void clear(void) { G.clear(); }
    inline void resize(int n) { G.resize(n + 1); }
    std::vector<Edge> &operator[](int x) { return G[x]; }
    inline void add_directed(int u, int v, W w = W{}) {
        G[u].push_back({v, w});
    }
    inline void add_undirected(int u, int v, W w = W{}) {
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    std::vector<W> dijkstra(int s) { // by default the shortest path.
        using Node = std::pair<W, int>;
        std::vector<W> dis(G.size(), std::numeric_limits<W>::max());
        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> heap;
        heap.push({W{}, s});
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            if (dis[t.second] != t.first) {
                continue;
            }
            for (auto &edge : G[t.second]) {
                if (dis[edge.to] > t.first + edge.w) {
                    dis[edge.to] = t.first + edge.w;
                    heap.push({dis[edge.to], edge.to});
                }
            }
        }
        return dis;
    }
};

#endif // ALGR_GRAPH