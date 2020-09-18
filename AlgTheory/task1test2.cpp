#include "IntIndColl.h"
#include <iostream>
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
        data = rand() % capacity +1;
        array.store(i, data);
    }

    for(i = 0; i < capacity; i++)
    {
        data = array.retrieve(i);
        cout << data << " ";
        
    }

    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array.retrieve(i);
        j = i;
        while ((j > 0) && array.retrieve(j - 1) > key)
        {
            array.store(j, data) = array.retrieve(j - 1);
            j--;
        }
        array.retrieve(j) = key;

    }



   


}