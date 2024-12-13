template <class T>
class Heap
{
protected:
    T *elements;
    int capacity;
    int count;

public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[] elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }

private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

// Your code here
template <class T>
int Heap<T>::getItem(T item)
{
    // TODO: return the index of item in heap
    for (int i = 0; i < this->count; i++)
    {
        if (this->elements[i] == item)
            return i;
    }
    return -1;
}

template <class T>
void Heap<T>::remove(T item)
{
    // TODO: remove the element with value equal to item
    int foundIndex = getItem(item);

    if (foundIndex == -1)
        return;

    this->elements[foundIndex] = this->elements[count - 1];
    this->count--;
    reheapDown(foundIndex);
}

template <class T>
void Heap<T>::clear()
{
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    delete[] this->elements;

    this->count = 0;
    this->elements = new T[capacity];
}