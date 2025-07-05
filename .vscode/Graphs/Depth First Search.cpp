#include <iostream>
#include <vector>
#include <stack>
#include <memory>

using namespace std;

struct Vertex {
    char label;
    bool visited;

    Vertex(char lbl) : label(lbl), visited(false) {}
};

class Graph {
private:
    static constexpr int MAX = 5;
    vector<unique_ptr<Vertex>> vertices;
    vector<vector<int>> adjMatrix;
    stack<int> vertexStack;

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

    void depthFirstSearch() {
        if (vertices.empty()) return;

        vertices[0]->visited = true;
        displayVertex(0);
        vertexStack.push(0);

        while (!vertexStack.empty()) {
            int current = vertexStack.top();
            int next = getAdjUnvisitedVertex(current);

            if (next == -1) {
                vertexStack.pop();
            } else {
                vertices[next]->visited = true;
                displayVertex(next);
                vertexStack.push(next);
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

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);

    cout << "Depth First Search: ";
    graph.depthFirstSearch();
    cout << endl;

    return 0;
}
