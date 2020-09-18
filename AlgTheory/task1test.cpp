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

template<typename T>
void indColl<T>::Store(int index, T)
{
    if((index < 0) || (index > size-1))
    {
        cerr << "\nERROR: index out of range\n";      
        exit(1);
    }

    collection[index] = T;
}





/*void insertionSort(indColl<int> *array, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i]; // take value
        j = i;
        while(j > 0 && array[j-1] > key)
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = key; // insert into correct place
    }
}


void display(indColl<int> *array, int size) //outputs array
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
*/



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