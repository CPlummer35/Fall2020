#include <iostream>
#include <chrono>
//#include "IntIndColl.h"

using namespace std;

template <class T>
class indColl
{
    public:
        indColl(int sz = 100);
        ~indColl();
        void Store(int, T);
        T& Retrieve(int) const;
        indColl(const indColl&)
        T& operator[](int);
    private: 
        T *collection;
        int size;
};

template <typename T>
indColl<T>::indColl(int sz)
{
    size = sz;
    collection = new int[sz];
}

template <typename T>
indColl<T>::~indColl()
{
    delete [] collection;
}

template <typename T>
T& operator[](int index)
{
    if((index < 0) || (index > size-1))
    {
        cerr << "\nError: index is out of range";
        exit(1);
    }
    return collection[index];
}







int main()
{
    int capacity, size, data;
    cout << "Enter Array Size: ";
    cin >> capacity;
    indColl<int> array(size);
    cout << "How much of the Array is occupied? ";
    cin >> capacity;
    for(int i = 0; i < capacity; i++)
    {
        data = rand() % capacity;
        array.Store(i, data);


    }



    

}