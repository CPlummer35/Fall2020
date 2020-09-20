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

IntIndColl::IntIndColl(const IntIndColl& source)
{
    size = source.size;
    collection = new int[size];
    for(int i = 0; i < source.size; i++)
    {
        collection[i] = source.collection[i];
    }
}

void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void merge(const IntIndColl& array, int l, int m, int r) 
{
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   IntIndColl larr(nl), rarr(nr);
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   IntIndColl array(n);     //create an array with given number of elements
   for(int i = 0; i<n; i++) 
   {
      array[i] = rand() % n + 1;
   }
   
   mergeSort(array, 0, n-1);     //(n-1) for last index
   cout << "Array after Sorting: ";
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


    



}
