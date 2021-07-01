# [Course schedule](https://leetcode.com/problems/course-schedule)
# topological sort solution based on BFS
```python
# time complexity: O(V+E)
# space complexity: o(V+E) as we are using V+E to keep the graph information in the collections.defaltdict. We are using O(1) or O(V) to keep the res depends on whether we need output the courses information.
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        indegree = [0]*numCourses
        graph = collections.defaultdict(list)
        for take, require in prerequisites:
            indegree[take] +=1
            graph[require].append(take)
        dq = [i for i, take in enumerate(indegree) if take==0]
        dq = collections.deque(dq)
        # if we want to save memory, we can set res = 0  as this problem is not needed to output the order.
        res = []
        while dq:
            zero_indegree = dq.popleft()
            res.append(zero_indegree)
            for node in graph[zero_indegree]:
                indegree[node] -= 1
                if indegree[node]==0:
                    dq.append(node)
        return len(res) == numCourses
```
C++
```cpp
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graphs(n);
        for (auto prerequisit: prerequisites)
        {
            auto u = prerequisit[0], v = prerequisit[1];
            graphs[u].push_back(v);
            indegree[v] += 1;
        }
        queue<int> zero_in_degree;
        for (int i = 0; i < n; ++i){
            if (indegree[i] == 0) zero_in_degree.push(i);
        }
        vector<int> courses;
        while (!zero_in_degree.empty()){
            auto u = zero_in_degree.front();zero_in_degree.pop();
            courses.push_back(u);
            for (auto v : graphs[u]){
                indegree[v] -= 1;
                if (indegree[v] == 0) zero_in_degree.push(v);
            }
        }
        return courses.size() == n;   
    }
};
```
