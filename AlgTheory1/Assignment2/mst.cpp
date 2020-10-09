// C++ program for Kruskal's algorithm to find Minimum Spanning Tree 
#include <iostream> 
#include <fstream>
#include "node.h"
#include "LinkedList.h"
#include <string>
using namespace std; 

bool contains_number(string &line)
{
	return (line.find_first_of("0123456789") != std::string::npos);
}

int main() 
{
	LinkedList<string> linkedList = LinkedList<string>();
	ifstream inf;
	inf.open("distances.txt"); //open a file to perform read operation using file object
   	if (inf.is_open())
	{   
    	string line;

    	while(inf >> line)
		{ //read data from file object and put it into string.
        	if(line.find("*") == std::string::npos)
			{
				if (contains_number(line) != true)
				{
					linkedList.InsertHead(line);
				}
				
			}
			
			
			

      	}
		inf.close(); //close the file object.

		linkedList.PrintList();
   }
   
   

  	/*linked list testing
    // NULL
    

    // 43->NULL
    linkedList.InsertHead(43);

    // 76->43->NULL
    linkedList.InsertHead(76);

    // 76->43->15->NULL
    linkedList.InsertTail(15);

    // 76->43->15->44->NULL
    linkedList.InsertTail(44);

    // Print the list element
    cout << "First Printed:" << endl;
    linkedList.PrintList();
    cout << endl;

    // 76->43->15->44->100->NULL
    linkedList.Insert(4, 100);

    // 76->43->15->48->44->100->NULL
    linkedList.Insert(3, 48);

    // 22->76->43->15->48->44->100->NULL
    linkedList.Insert(0, 22);

    // Print the list element
    cout << "Second Printed:" << endl;
    linkedList.PrintList();
    cout << endl;

    // Get value of the second index
    // It should be 43
    cout << "Get value of the second index:" << endl;
    Node<int> * get = linkedList.Get(2);
    if(get != NULL)
        cout << get->Value;
    else
        cout << "not found";
    cout << endl << endl;

    // Find the position of value 15
    // It must be 3
    cout << "The position of value 15:" << endl;
    int srch = linkedList.Search(15);
    cout << srch << endl << endl;

    // Remove first element
    cout << "Remove the first element:" << endl;
    linkedList.Remove(0);
    // 76->43->15->48->44->100->NULL
    linkedList.PrintList();
    cout << endl;

    // Remove fifth element
    cout << "Remove the fifth element:" << endl;
    linkedList.Remove(4);
    // 76->43->15->48->100->NULL
    linkedList.PrintList();
    cout << endl;

    // Remove tenth element
    cout << "Remove the tenth element:" << endl;
    linkedList.Remove(9);
    // Nothing happen
    // 76->43->15->48->100->NULL
    linkedList.PrintList();
    cout << endl;

	*/




	return 0; 
} 

