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

# code in python
```python
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], src: int, dst: int) -> float:
        # init
        dis = [0]*n
        dis[src] = 1.0
        # build the graph
        graphs = collections.defaultdict(list)
        for (u, v), prob in zip(edges, succProb):
            graphs[u].append((v, prob))
            graphs[v].append((u, prob))
        # print(graphs)
        # max heap this time
        # python default is min heap, how can we have a max heap?
        # the idea is simple, using -x instead of x. min heap,  [10, 8, 2], [-10, -8, -2]
        pq = []
        heapq.heapify(pq)
        # by using a negative value, we can change the min heap to max heap
        heapq.heappush(pq, (-1.0, src))
 
        while pq:
            cost, u = heapq.heappop(pq)
            # lazy delection
            if -cost < dis[u]:continue
            for v, p in graphs[u]:
                newcost = -cost*p
                if newcost > dis[v]:
                    # if we find a better one
                    # update
                    # 1. remove old value, we do it in lazy deletion
                    # 2. update the dis
                    # 3. append the new value
                    dis[v] = newcost
                    heapq.heappush(pq, (-newcost, v))
                
        return dis[dst]
```
