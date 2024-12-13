#include <iostream>
using namespace std;
template <class T>
class DGraph
{
public:
    class VertexNode; // Forward declaration
    class Edge;       // Forward declaration
protected:
    VertexNode *nodeList; // list of vertexNode of DGraph
    int countVertex;
    int countEdge;

public:
    DGraph()
    {
        this->nodeList = nullptr;
        this->countEdge = 0;
        this->countVertex = 0;
    }
    ~DGraph() {};
    VertexNode *getVertexNode(T vertex);
    void add(T vertex);

    void connect(T from, T to, float weight = 0);

    void removeVertex(T removeVertex);
    bool removeEdge(T from, T to);
    string shape();
    bool empty();
    void clear();
    void printGraph();

public:
    class VertexNode
    {
    private:
        T vertex;
        Edge *adList; // list of adjacent edge of this vertex
        VertexNode *next;

        friend class Edge;
        friend class DGraph;

    public:
        VertexNode(T vertex, Edge *adList = nullptr, VertexNode *next = nullptr)
        {
            this->vertex = vertex;
            this->adList = adList;
            this->next = next;
        }
        string toString();
        void addAdjacentEdge(Edge *newEdge);
        bool connectTo(VertexNode *toNode, float weight = 0);
        bool removeTo(VertexNode *toNode);
        Edge *getEdge(VertexNode *toNode);
    };

    class Edge
    {
    private:
        VertexNode *fromNode;
        VertexNode *toNode;
        float weight;
        Edge *next;

        friend class VertexNode;
        friend class DGraph;

    public:
        Edge(VertexNode *fromNode, VertexNode *toNode, float weight = 0.0, Edge *next = nullptr)
        {
            this->fromNode = fromNode;
            this->toNode = toNode;
            this->weight = weight;
            this->next = next;
        }
        string toString();
    };
};

template <class T>
string DGraph<T>::shape()
{
    // TODO: return the string with format: [Vertices: <numOfVertex>, Edges: <numOfEdge>]
    stringstream os;
    os << "[Vertices: " << this->countVertex << ", Edges: " << this->countEdge << "]";
    return os.str();
}

template <class T>
bool DGraph<T>::empty()
{
    // TODO: return if graph is empty (it doesn't have any vertex and edge)
    return this->countVertex == 0 || this->countEdge == 0;
}

template <class T>
void DGraph<T>::clear()
{
    // TODO: remove all edges and vertices of graph.
    VertexNode *currentNode = this->nodeList;
    while (currentNode)
    {
        Edge *currentEdge = currentNode->adList;
        while (currentEdge)
        {
            Edge *nextEdge = currentEdge->next;
            delete currentEdge;
            currentEdge = nextEdge;
        }
        currentNode->adList = nullptr;
        currentNode = currentNode->next;
    }
    while (this->nodeList)
    {
        VertexNode *nextNode = this->nodeList->next;
        delete this->nodeList;
        this->nodeList = nextNode;
    }

    this->countVertex = 0;
    this->countEdge = 0;
}
