# [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
We can change this problem into SSSP problem by change each node to:
- node with 0 stop
- node with 1 stop
- ...
- node with k stop
And solve it by using a slightly modified SSSP approach.
## Naive dijkstra algorithm
```cpp
/*
jimmy shen
time complexity O((V + E) * log V) -> as V = kn, E = flights.size() the complexity is (O(kn + E) * log (kn))
space complexity O(V) = O(kn)
*/


const int INF = INT_MAX;
typedef pair<int, int> PII;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // init
        vector<vector<int>> dis(n, vector<int>(n, INF));dis[src][0] = 0;
        set<pair<int, PII>> pq;
        // build the graph
        vector<vector<PII>> AL(n);
        for (auto &x: flights){
            int from = x[0], to = x[1], price = x[2];
            AL[from].emplace_back(to, price);
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j) {
               if (i == src && j == 0) pq.emplace(0, make_pair(i, 0));
                else pq.emplace(INF, make_pair(i, j));
            }
        }
        // naive dijkstra algorithm
        while (!pq.empty()){
            auto [cost, node_stop] = *pq.begin();
            auto [node, stop] = node_stop;
            pq.erase(pq.begin());
            if (stop + 1 > n - 1 || cost == INF) continue;
            for (auto [v, w]: AL[node]) {
                int newcost = cost + w;
                if (newcost >= dis[v][stop+1]) continue;
                pq.erase(pq.find({dis[v][stop+1], make_pair(v, stop + 1)}));
                dis[v][stop+1] = newcost;
                pq.emplace(newcost, make_pair(v, stop + 1));
            }
        }
        
        int ret = INF;
        for (int stop = 0; stop <= min(k + 1, n - 1); ++stop) ret = min(ret, dis[dst][stop]);
        return ret == INF? -1: ret;
    }
};
```
## Modified dijkstra algorithm
```cpp
typedef pair<int, int> PII;
const int INF = INT_MAX;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // init, for each node we also consider how many trips do we have when reaching this node.
        // 0, 1, 2, .. n -1 
        vector<vector<int>> dis(n, vector<int>(n + 1, INF));
        
        dis[src][0] = 0;
        // build the graphs
        // {0: {{1, 100}, {2, 500}}
        vector<vector<PII>> graphs(n);
        for (auto &flight : flights)
        {
            auto from = flight[0], to = flight[1], price = flight[2];
            graphs[from].emplace_back(to, price);
        }
        // we need a min heap. We know that C++ default is max prioqiry
        // {cost, {node, trip}}
        priority_queue<pair<int, PII>, vector<pair<int, PII>>,
                                        greater<pair<int, PII>>> pq;
        pq.emplace(0, make_pair(src, 0));
        while (!pq.empty())
        {
            auto [cost, nodeTrip] = pq.top(); pq.pop();
            auto [u, trip] = nodeTrip;
            // out of boundary protection
            if (trip + 1 > n - 1) continue;
            // lazy deletion
            if (cost > dis[u][trip]) continue;
            for (auto [v, weight]: graphs[u])
            {
                auto newCost = cost + weight;
                if (newCost < dis[v][trip + 1])
                {
                    // update
                    // 1) delete the old one. See lazy deletion
                    // 2) update the distance
                    // 3) put it into the pq
                    dis[v][trip + 1] = newCost;
                    pq.emplace(newCost, make_pair(v, trip + 1));
                }
            }
        }
        int ret = INF;
        /*
        you have at most k stops
        you have at most k + 1 trips
        dis[dst][i] for i from 0 to k + 1
        */
        
        int maxTrips = min(k + 1, n - 1);
        
        for (int trip = 0; trip <= maxTrips; trip++)
        {
            ret = min(ret, dis[dst][trip]);
        }
      
        return ret == INF? -1 : ret;
    }
};
```


