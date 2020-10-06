#include "IntIndColl.h"
#include <iostream>
#include <chrono>
using namespace std;

IntIndColl::IntIndColl(int sz)
{
    size = sz;
    collection = new int [sz];
}

IntIndColl::~IntIndColl()
{
    delete [] collection;
}

void IntIndColl::store(int index, int value)
{
    if((index < 0) || (index > size-1))
    {
        cerr << "\nERROR: index out of range\n";      
        exit(1);
    }
    collection[index] = value;
}

int IntIndColl::retrieve(int index) const
{
    if ((index < 0) || (index > size - 1))
    {
        cerr << "\nERRROR: index out of range \n";
        exit(1);
    }
    return collection[index];
}

int& IntIndColl::operator[](int index)
{
    if((index < 0) || (index > size-1))
    {
        cerr << "\nError: index is out of range";
        exit(1);
    }
    return collection[index];
}

IntIndColl::IntIndColl(IntIndColl& source)
{
    size = source.size;
    collection = new int[size];
    for(int i = 0; i < source.size; i++)
    {
        collection[i] = source.collection[i];
    }
}

int main()
{
    int size, capacity, i, data;
    cout << "Enter Array Size: ";
    cin >> size;
    IntIndColl array(size);
    cout << "how much of the array is occupied?: ";
    cin >> capacity;
    for(i = 0; i < capacity; i++)
    {
        array[i] = rand() % capacity +1;
    }
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i;
        while(j > 0 && array[j-1] > key)
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = key;
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s\n";
}




   


