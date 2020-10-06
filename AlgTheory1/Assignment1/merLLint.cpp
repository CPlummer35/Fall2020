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

void LLIntIndColl::store(long long int index, long long int value)
{
    if((index < 0) || (index > size-1))
    {
        cerr << "\nERROR: index out of range\n";      
        exit(1);
    }

    collection[index] = value;
}

long long int LLIntIndColl::retrieve(long long int index) const
{
    if ((index < 0) || (index > size - 1))
    {
        cerr << "\nERRROR: index out of range \n";
        exit(1);
    }

    return collection[index];
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

void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void merge(LLIntIndColl& array, long long int l, long long int m, long long int r) 
{
   long long int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   LLIntIndColl larr(nl), rarr(nr);
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
void mergeSort(LLIntIndColl& array, long long int l, long long int r) {
   long long int m;
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
   LLIntIndColl array(n);     //create an array with given number of elements
   for(int i = 0; i<n; i++) 
   {
      array[i] = rand() % n + 1;
   }
   std::chrono::time_point<std::chrono::system_clock> start, end;
   start = std::chrono::system_clock::now();
   
   mergeSort(array, 0, n-1);     //(n-1) for last index

   end = std::chrono::system_clock::now();
    
   std::chrono::duration<double> elapsed_seconds = end - start;
   cout << elapsed_seconds.count() << "s\n";
  
}