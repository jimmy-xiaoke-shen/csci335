# [binary search: Minimum Spanning Tree](https://binarysearch.com/problems/Minimum-Spanning-Tree)

We can using MST to solve the problem.
Step 1: Using the standard way to compute the MST cost.
Step 2: Force put the a, b into your MST output and building the MST based on this. When done, check whether the cost here is same as the MST cost in step 1

```cpp
// time complexity: O(E log E)
class UF 
{
    vector<int> root;
    public:
    UF(int N) : root(N) 
    {
        for (int i = 0; i < N; ++i)
            root[i] = i;
    }
    
    void union_(int x, int y) 
    {
        root[find(y)] = root[find(x)];
    }
  
    int find(int x) 
    {
        if (x != root[x])root[x] = find(root[x]);
        return root[x];
    }
};

bool solve(vector<vector<int>>& edges, int a, int b) {
      // Kruskal's algorithm first round
        const int n  = edges.size();
        UF uf(n+1);
        sort(edges.begin(), edges.end(), [](auto& a, auto& b){return a[2] < b[2];});
        int ret = 0, i = 0;
        int a_b_cost = 0;
        for (auto& edge : edges) 
        {
            if ((edge[0] == a && edge[1] == b) ||(edge[1] == a && edge[0] == b) ) a_b_cost = edge[2];
            if (uf.find(edge[0]) != uf.find(edge[1])) 
            {
                ++i;
                ret += edge[2];
                if (i==n)break;
                uf.union_(edge[0], edge[1]);
            }
        }
        int MSTCost = ret;
        // Kruskal's algorithm second round by putting the a,b into the result at the initial step
        UF uf1(n+1);
        int MSTabCost = a_b_cost;
        i = 1;
        uf1.union_(a, b);
        for (auto& edge : edges) 
        {
            if (uf1.find(edge[0]) != uf1.find(edge[1])) 
            {
                ++i;
                MSTabCost += edge[2];
                if (i==n)break;
                uf1.union_(edge[0], edge[1]);
            }
        }
    return MSTabCost == MSTCost;
}
```
