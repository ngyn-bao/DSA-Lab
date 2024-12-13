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
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]";
    }

private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
};

// Your code here
template <class T>
void Heap<T>::push(T item)
{
    ensureCapacity(count + 1);
    this->elements[count] = item;
    reheapUp(count);
    this->count++;
}

template <class T>
void Heap<T>::ensureCapacity(int minCapacity)
{
    if (minCapacity > capacity)
    {
        int newCapacity = max(capacity * 2, minCapacity);
        T *newElements = new T[newCapacity];
        for (int i = 0; i < count; i++)
        {
            newElements[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = newElements;
        this->capacity = newCapacity;
    }
}

template <class T>
void Heap<T>::reheapUp(int position)
{
    int parent = (position - 1) / 2;
    while (position > 0 && this->elements[position] > this->elements[parent])
    {
        swap(this->elements[position], this->elements[parent]);
        position = parent;
        parent = (position - 1) / 2;
    }
}