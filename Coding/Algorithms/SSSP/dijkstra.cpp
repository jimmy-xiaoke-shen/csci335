#include<iostream>
#include<vector>
#include<queue>
#include<set>
const int INF = INT_MAX;
using namespace std;
typedef pair<int, int> PII;
void modified_dijkstra(int n, vector<vector<PII>> &graph, int src, int dst)
{  // init distance from src to a node
   vector<int> dis(n, INF); dis[src] = 0;
   // python syntex: dis = [float("inf")]*n
   priority_queue<PII, vector<PII>, greater<PII>> pq;
   // init the unexplored nodes
   for (int i = 0; i < n; ++i) 
   {
      if (i == src) pq.emplace(0, i);
      else pq.emplace(INF, i);
   }
   while (!pq.empty())
   {
     // pick up the shorted node from unexplored nodes
     auto [cost, u] = pq.top(); pq.pop();
     // soft delection here
     if (cost > dis[u]) continue;
     // explore neighbors
     for (auto &[v, weight]: graph[u])
     {
        int new_cost = cost + weight;
        // find a shorter path:
        if (new_cost < dis[v])
        {
           // update
           // can not the old one now
           // pq.erase(pq.find({dis[v], v}));
           // update the dis[v] to the new one
           dis[v] = new_cost;
           // put the new one into the priority queue
           pq.emplace(dis[v], v);
        }
     }
   }
   for (int i = 0; i < n; ++i)
   {
      cout << "shortest distance from src: " << src << " to node " << i << " is: " << dis[i] << endl;
   }
   return;
}
void naive_dijkstra(int n, vector<vector<PII>> &graph, int src, int dst)
{  // init distance from src to a node
   vector<int> dis(n, INF); dis[src] = 0;
   // python syntex: dis = [float("inf")]*n
   set<PII> pq;
   // init the unexplored nodes
   for (int i = 0; i < n; ++i) 
   {
      if (i == src) pq.emplace(0, i);
      else pq.emplace(INF, i);
   }
   while (!pq.empty())
   {
     // pick up the shorted node from unexplored nodes
     auto [cost, u] = *(pq.begin()); pq.erase(pq.begin());
     // explore neighbors
     for (auto &[v, weight]: graph[u])
     {
        int new_cost = cost + weight;
        // find a shorter path:
        if (new_cost < dis[v])
        {
           // update
           // delete the old one
           pq.erase(pq.find({dis[v], v}));
           // update the dis[v] to the new one
           dis[v] = new_cost;
           // put the new one into the set
           pq.emplace(dis[v], v);
        }
     }
   }
   for (int i = 0; i < n; ++i)
   {
      cout << "shortest distance from src: " << src << " to node " << i << " is: " << dis[i] << endl;
   }
   return;
}
int main()
{
   int n, num_edges;
   cin >> n >> num_edges;
   int u, v, weight;
   
   //using adjancency list to build the graph
   // graph[0] = {{1, 2},{3, 10}}
   vector<vector<PII>> graph(n);
   for (int i = 0; i < num_edges; ++i) 
   {
      cin >> u >> v  >> weight;
      graph[u].emplace_back(v, weight);  
   }
   int src = 0, dst = 4;
   naive_dijkstra(n, graph, src, dst);
   modified_dijkstra(n, graph, src, dst);
   return 0;
}
