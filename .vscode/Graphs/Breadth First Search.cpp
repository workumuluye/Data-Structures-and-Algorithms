#include <iostream>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

class Vertex {
public:
    char label;
    bool visited;

    Vertex(char lbl) : label(lbl), visited(false) {}
};

class Graph {
private:
    static constexpr int MAX = 5;
    vector<unique_ptr<Vertex>> vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph() {
        adjMatrix.resize(MAX, vector<int>(MAX, 0));
    }

    void addVertex(char label) {
        if (vertices.size() < MAX) {
            vertices.push_back(make_unique<Vertex>(label));
        } else {
            cerr << "Vertex limit reached.\n";
        }
    }

    void addEdge(int start, int end) {
        if (start < MAX && end < MAX) {
            adjMatrix[start][end] = 1;
            adjMatrix[end][start] = 1;
        }
    }

    void displayVertex(int index) const {
        cout << vertices[index]->label << " ";
    }

    int getAdjUnvisitedVertex(int index) const {
        for (int i = 0; i < vertices.size(); ++i) {
            if (adjMatrix[index][i] == 1 && !vertices[i]->visited) {
                return i;
            }
        }
        return -1;
    }

    void breadthFirstSearch() {
        if (vertices.empty()) return;

        queue<int> q;

        vertices[0]->visited = true;
        displayVertex(0);
        q.push(0);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            int unvisitedVertex;
            while ((unvisitedVertex = getAdjUnvisitedVertex(current)) != -1) {
                vertices[unvisitedVertex]->visited = true;
                displayVertex(unvisitedVertex);
                q.push(unvisitedVertex);
            }
        }

        // Reset visited flags
        for (auto& vertex : vertices) {
            vertex->visited = false;
        }
    }
};

int main() {
    Graph graph;

    graph.addVertex('S');
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');

    graph.addEdge(0, 1); // S - A
    graph.addEdge(0, 2); // S - B
    graph.addEdge(0, 3); // S - C
    graph.addEdge(1, 4); // A - D
    graph.addEdge(2, 4); // B - D
    graph.addEdge(3, 4); // C - D

    cout << "Breadth First Search: ";
    graph.breadthFirstSearch();
    cout << endl;

    return 0;
}
