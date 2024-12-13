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
typename DGraph<T>::VertexNode *DGraph<T>::getVertexNode(T vertex)
{
    // TODO: Iterate through the Node list of the graph
    //       check if any vertexNode contains vertex.
    //       If such a vertexNode exists, return it; otherwise, return nullptr.
    VertexNode *current = this->nodeList;
    while (current)
    {
        if (current->vertex == vertex)
            return current;
        current = current->next;
    }
    return nullptr;
}

template <class T>
void DGraph<T>::add(T vertex)
{
    // TODO: create a new vertexNode with vertex.
    VertexNode *newVertex = new VertexNode(vertex);

    // TODO: add new vertexNode to the end of Node list of the graph.

    if (!this->nodeList)
        this->nodeList = newVertex;
    else
    {
        VertexNode *current = this->nodeList;
        while (current->next)
            current = current->next;
        current->next = newVertex;
    }

    // TODO: increase the countVertex.
    this->countVertex++;
}

template <class T>
void DGraph<T>::connect(T from, T to, float weight)
{
    // TODO: get vertexNode with "from" and vertexNode with "to".
    VertexNode *fromNode = this->getVertexNode(from);
    VertexNode *toNode = this->getVertexNode(to);

    // TODO: If either of the two vertexNode objects does not exist,
    //       throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    if (!fromNode || !toNode)
        throw VertexNotFoundException("Vertex doesn't exist!");

    // TODO: connect "from" vertexNode to "to" vertexNode.
    //       If a new edge is created, increase the countEdge.
    fromNode->connectTo(toNode, weight);
    this->countEdge++;
}
