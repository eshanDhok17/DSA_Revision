// Leetcode Daily

// Code 1 - Find if Path Exists in Graph

  class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(start == end) return true;
        
        // else build graph
        vector<vector<int>> graph(n);
        for(int i=0; i<size(edges); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);    
            graph[edges[i][1]].push_back(edges[i][0]);    
        }
        
        // Graph BFS
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(start);
        vis[start] = true;
        while(!q.empty()) {
            int top = q.front(); q.pop();
            if(top == end) return true;
            for(int i=0; i<graph[top].size(); ++i) {
                if(vis[graph[top][i]] == false) {
                    vis[graph[top][i]] = true;
                    q.push(graph[top][i]);
                }
            }
        }
        return false;
    }
};


// Code 2 - All Paths From Source to Target

class Solution {
public:
    void recordPath(vector<vector<int>> &graph, int &node, vector<int> &path, vector<vector<int>> &paths) {
        if(node == size(graph) - 1) {
            paths.push_back(path);
            return ;
        }
        for(int &otherNodes : graph[node]) {
            path.push_back(otherNodes);
            recordPath(graph, otherNodes, path, paths);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path = {0};
        int startNode = 0;
        recordPath(graph, startNode, path, paths);
        return paths;
    }
};