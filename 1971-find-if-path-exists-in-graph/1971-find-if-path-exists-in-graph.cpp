class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adjList(n);

        for (const vector<int>& edge : edges) {
            int first = edge[0];
            int second = edge[1];

            adjList[first].push_back(second);
            adjList[second].push_back(first);
        }

        vector<bool> visited(n, false);
        queue<int> pendingNodes;

        pendingNodes.push(source);
        visited[source] = true;

        while (!pendingNodes.empty()) {

            int node = pendingNodes.front();
            pendingNodes.pop();

            if (node == destination) {
                return true;
            }

            for (int nextNode : adjList[node]) {

                if (visited[nextNode] == false) {
                    visited[nextNode] = true;
                    pendingNodes.push(nextNode);
                }
            }
        }

        return false;
    }
};