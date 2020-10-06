#include "LLIntIndColl.h"
#include <iostream>
#include <chrono>
using namespace std;

LLIntIndColl::LLIntIndColl(long long int sz)
{
    size = sz;
    collection = new long long int [sz];
}

LLIntIndColl::~LLIntIndColl()
{
    delete [] collection;
}

long long int& LLIntIndColl::operator[](long long int index)
{
    if((index < 0) || (index > size-1))
    {
        cerr << "\nError: index is out of range";
        exit(1);
    }
    return collection[index];
}

LLIntIndColl::LLIntIndColl(LLIntIndColl& source)
{
    size = source.size;
    collection = new long long int[size];
    for(int i = 0; i < source.size; i++)
    {
        collection[i] = source.collection[i];
    }
}

int main()
{
    long long int size, capacity, i, data;

    cout << "Enter Array Size: ";
    cin >> size;
    LLIntIndColl array(size);
    cout << "how much of the array is occupied?: ";
    cin >> capacity;

    for(i = 0; i < capacity; i++)
    {
        array[i] = rand() % capacity +1;
    }

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();

    long long int key, j;
    for (long long int i = 1; i < size; i++)
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



    end = std::chrono::system_clock::now();
    
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s\n";
    
}
