#include<iostream>
using namespace std;

template <typename T>

class queue{
    T *data;
    int size;
    int firstIndex;
    int nextIndex;
    int capacity;

    public:

    queue(int capacity = 5)
    {
        data = new T[capacity];
        size = 0;
        firstIndex = -1;
        nextIndex = 0;
        this -> capacity = capacity;
    }

    T front()
    {
        return data[firstIndex];
    }

    int getSize()
    {
        return size;
    }

    bool empty()
    {
        return size == 0;
    }

    void enqueue(T value)
    {
        if(size == capacity)
        {
            T * new_data = new T[2*capacity];

            int j = 0;
            for(int i=firstIndex;i<capacity;i++)
            {
                new_data[j] = data[i];
                j++;
            }

            for(int i=0;i<firstIndex;i++)
            {
                new_data[j] = data[i];
                j++;
            }

            delete data;
            data = new_data;
            firstIndex = 0;
            nextIndex = size;
            capacity *= 2;
        }

        data[nextIndex] = value;
        nextIndex = (nextIndex+1) % capacity;
        if(firstIndex == -1)
            firstIndex = 0;
        size++;
    }

    void dequeue()
    {
        if(size == 0)
        {
            cout<<"Queue Empty"<<endl;
            return;
        }

        firstIndex = (firstIndex + 1)%capacity;
        size--;

        if(size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
    }
};