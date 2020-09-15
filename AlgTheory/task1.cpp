// insertion sort

#include <iostream>
#include <chrono>
using namespace std;

void display(int *array, int size) //outputs array
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int *array, int size)
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

int main()
{
    /*int n;
    cout << "enter number of values: ";
    cin >> n;
    int arr[n]; // creates array of size n
    cout << "enter elements to be sorted:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    */

   int unsorted[500000];
   for (int i = 0; i < 500000; i++)
   {
       unsorted[i] = rand() % 500000 + 1; 
   }

   //display(unsorted, 100000);
   //cout << endl;
   //insertionSort(unsorted, 500000);
   //display(unsorted, 100000);


   

    /*cout << "Array before sorting: ";
    display(arr, n);
    insertionSort(arr, n);
    cout << "array after sorting: ";
    display(arr, n);
    */
    

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    insertionSort(unsorted, 500000);
    end = std::chrono::system_clock::now();
    
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << elapsed_seconds.count() << "s\n";
    

}

