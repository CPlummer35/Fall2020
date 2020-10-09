// C++ program for Kruskal's algorithm to find Minimum Spanning Tree 
#include <iostream> 
#include <fstream>
#include "node.h"
#include "LinkedList.h"
#include <string>
using namespace std; 

bool contains_number(const std::string &line)
{
    if (line.find('0') != std::string::npos ||
        line.find('1') != std::string::npos ||
        line.find('2') != std::string::npos ||
        line.find('3') != std::string::npos ||
        line.find('4') != std::string::npos ||
        line.find('5') != std::string::npos ||
        line.find('6') != std::string::npos ||
        line.find('7') != std::string::npos ||
        line.find('8') != std::string::npos ||
        line.find('9') != std::string::npos)
    {
        return true;
    }

    return false;
}

int main() 
{
	LinkedList<string> linkedList = LinkedList<string>();
	ifstream inf;
	inf.open("distances.txt"); //open a file to perform read operation using file object
   	if (inf.is_open())
	{  
    	string line;

    	while(getline(inf, line))
		{ //read data from file object and put it into string.

            
            while(getline(inf, line))
            { //read data from file object and put it into string.
                if(line.find("*") == std::string::npos)
                {
                    if (line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)
                    {
                        if(line != "") 
                        {
                            string newLine;
                            newLine = line.substr(0,line.find("["));
                            linkedList.InsertHead(newLine);
                        }
                    } 
                    else 
                    {
                        // Is the distances
                    }
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

