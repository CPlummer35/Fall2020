// C++ program for Kruskal's algorithm to find Minimum Spanning Tree 
#include <iostream> 
#include <fstream>
#include "node.h"
#include "LinkedList.h"
#include <string>
using namespace std; 

int main(int argc, char **argv) 
{
	LinkedList<string> linkedList = LinkedList<string>();
	ifstream inf;

	inf.open(argv[1]); //open a file to perform read operation using file object
   	if (inf.is_open())
	{  
    	string line;
        bool processingCity = false;
        string cityState;
        // Array of distance

        
        
        while(getline(inf, line))
        { //read data from file object and put it into string.
            if(line.find("*") == std::string::npos)
            {
                if (line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)
                {
                    if(processingCity) {
                        linkedList.InsertHead(cityState);
                        cityState = "";
                        processingCity = false;
                    }
                    if(line != "") 
                    {
                        cityState = line.substr(0,line.find("["));
                        processingCity = true;
                    }
                } 
                else 
                {
                    // Is the distances
                    cout << line << endl;
                    // Split the distance line string into an array of integers
                }
            }
        }
    }
        
        

    linkedList.PrintList();
	inf.close(); //close the file object.
    
   
   
   

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

