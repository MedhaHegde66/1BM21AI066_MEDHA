#include <iostream>
#include <queue>
#include <vector>

class Digraph {
public:
    Digraph(int vertices) : numVertices(vertices), adjLists(vertices) {}
    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
    }
    void BFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);
        while (!q.empty()) {
            int currVertex = q.front();
            q.pop();
            std::cout << "Visited " << currVertex << " ";
            for (int adjVertex : adjLists[currVertex]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }
    }
private:
    int numVertices;
    std::vector<std::vector<int>> adjLists;
};

int main() {
    Digraph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    return 0;
}
