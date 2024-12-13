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
bool DGraph<T>::removeEdge(T from, T to)
{
    // TODO: get vertexNode with "from" and vertexNode with "to".
    VertexNode *fromNode = this->getVertexNode(from);
    VertexNode *toNode = this->getVertexNode(to);
    // TODO: If either of the two vertexNode objects does not exist,
    //       throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    if (!fromNode || !toNode)
        throw VertexNotFoundException("Vertex doesn't exist!");

    // TODO: Delete the edge between the "from" vertexNode and the "to" vertexNode. (use removeTo method)
    //       If success return true and decrement the countEdge; otherwise, return false;
    bool edgeRemove = fromNode->removeTo(toNode);
    if (edgeRemove)
    {
        this->countEdge--;
        return true;
    }
    return false;
}

template <class T>
void DGraph<T>::removeVertex(T removeVertex)
{
    // TODO: get vertexNode with "removeVertex"
    VertexNode *removeNode = this->getVertexNode(removeVertex);

    // TODO: If this vertexNode isn't existed,
    //       throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    if (!removeNode)
        throw VertexNotFoundException("Vertex doesn't exist!");

    // TODO: Iterate through all the vertexNode in the graph's Node list. For each vertexNode:
    //       - Check for an edge from the current vertex to the "removeVertex".
    //       If such an edge exists, delete it (use removeTo method) and decrement the countEdge.

    //      - Check for an edge from the "removeVertex" to the current vertex.
    //      If such an edge exists, delete it (use removeTo method) and decrement the countEdge.
    VertexNode *current = this->nodeList;
    while (current)
    {
        if (current != removeNode && current->removeTo(removeNode))
            this->countEdge--;

        if (removeNode->removeTo(current))
        {
            this->countEdge--;
        }

        current = current->next;
    }

    // TODO: Delete the vertexNode containing removeVertex from the Node list of the graph
    //       Decrement the countVertex.
    if (this->nodeList == removeNode)
    {
        this->nodeList = removeNode->next;
    }
    else
    {
        VertexNode *prev = nullptr;
        current = this->nodeList;
        while (current && current != removeNode)
        {
            prev = current;
            current = current->next;
        }
        if (prev)
        {
            prev->next = current->next;
        }
    }
    delete removeNode;
    this->countVertex--;
}
