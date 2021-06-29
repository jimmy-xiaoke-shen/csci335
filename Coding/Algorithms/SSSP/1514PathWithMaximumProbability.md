# [1514. Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/)
# The standard dijkstra algorithm is finding the minimum path. For this problem, it is fining the maximum path.

```cpp
/*
jimmy shen
Time complexity: O((V + E) log E)
Space complexity: O(E)
*/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dst) {
        // init
        vector<double> dis(n, 0);dis[src] = 1.0;
        priority_queue<pair<int, double>> pq;
        vector<vector<pair<int, double>>> graph(n);
        // build the graph
        const int m = edges.size();
        for (int i = 0; i < m; ++i)
        {
            auto u = edges[i][0], v = edges[i][1];
            auto prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        // modified dijkstra algorithm
        pq.emplace(src, 1.0);
        while (!pq.empty())
        {
            auto [node, prob] = pq.top(); pq.pop();
            // lazy delection
            if (prob < dis[node]) continue;
            for (auto &[v, thisProb]: graph[node])
            {
                double newProb = prob*thisProb;
                if (newProb > dis[v]) {
                    dis[v] = newProb;
                    pq.emplace(v, newProb);
                }
            }
        }
        return dis[dst]; 
    }
};
```
