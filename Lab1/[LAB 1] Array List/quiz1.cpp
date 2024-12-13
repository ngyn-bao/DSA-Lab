#include <bits/stdc++.h>
using namespace std;

template <class T>
class ArrayList
{
protected:
    T *data;      // dynamic array to store the list's items
    int capacity; // size of the dynamic array
    int count;    // number of items stored in the array
public:
    ArrayList()
    {
        capacity = 5;
        count = 0;
        data = new T[5];
    }
    ~ArrayList() { delete[] data; }
    void add(T e);
    void add(int index, T e);
    int size();
    void ensureCapacity(int index);
};

template <class T>
void ArrayList<T>::ensureCapacity(int cap)
{
    /*
        if cap == capacity:
            new_capacity = capacity * 1.5;
            create new array with new_capacity
        else: do nothing
    */
    if (cap == this->capacity)
    {
        int new_capacity = this->capacity * 1.5;

        T *new_data = new T[new_capacity];
        for (int i = 0; i < this->count; i++)
        {
            new_data[i] = this->data[i];
        }

        delete[] this->data;
        this->data = new_data;
        this->capacity = new_capacity;
    }
    else
        return;
}

template <class T>
void ArrayList<T>::add(T e)
{
    /* Insert an element into the end of the array. */
    ensureCapacity(this->count);
    this->data[count] = e;
    this->count++;
}

template <class T>
void ArrayList<T>::add(int index, T e)
{
    /*
        Insert an element into the array at given index.
        if index is invalid:
            throw std::out_of_range("the input index is out of range!");
    */

    if (index < 0 || index > this->capacity)
        throw std::out_of_range("the input index is out of range!");

    ensureCapacity(this->count + 1);

    for (int i = this->count; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = e;
    this->count++;
}

template <class T>
int ArrayList<T>::size()
{
    /* Return the length (size) of the array */
    return this->count;
}