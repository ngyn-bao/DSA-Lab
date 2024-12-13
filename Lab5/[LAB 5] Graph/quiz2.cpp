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
typename DGraph<T>::Edge *DGraph<T>::VertexNode::getEdge(VertexNode *toNode)
{
    // TODO: Iterate through the adjacency list of this vertex
    //       checking if there exists an edge with this vertex as the starting vertex
    //       and "toNode" as the ending vertex.
    //       If not return nullptr, else return that edge.
    Edge *currentEdge = this->adList;
    while (currentEdge)
    {
        if (currentEdge->toNode == toNode)
        {
            return currentEdge;
        }
        currentEdge = currentEdge->next;
    }
    return nullptr;
}

template <class T>
void DGraph<T>::VertexNode::addAdjacentEdge(Edge *newEdge)
{
    // TODO: add newEdge to adjacency list of this vertex.
    newEdge->next = this->adList;
    this->adList = newEdge;
}

template <class T>
bool DGraph<T>::VertexNode::connectTo(VertexNode *toNode, float weight)
{
    // TODO: get edge from this node to "toNode".
    Edge *existEdge = this->getEdge(toNode);

    // TODO: If the edge is not existed, create a new Edge and add it to the adjacency list.
    //       If the edge is existed, update its weight.
    if (existEdge)
    {
        existEdge->weight = weight;
        return false;
    }

    Edge *newEdge = new Edge(this, toNode, weight);
    this->addAdjacentEdge(newEdge);
    return true;

    // TODO: Return true if a new Edge is created; otherwise, return false.
}

template <class T>
bool DGraph<T>::VertexNode::removeTo(VertexNode *toNode)
{
    if (!this->adList)
    {
        return false;
    }
    // TODO: remove the edge with "toNode" as the ending vertex from this node's adjacency list.
    Edge *prevEdge = nullptr;
    Edge *currentEdge = this->adList;

    while (currentEdge)
    {
        if (currentEdge->toNode == toNode)
        {
            if (prevEdge)
            {
                prevEdge->next = currentEdge->next;
            }
            else
            {
                this->adList = currentEdge->next;
            }
            delete currentEdge;
            return true;
        }
        prevEdge = currentEdge;
        currentEdge = currentEdge->next;
    }

    // TODO: return true if success; otherwise, return false.
    return false;
}