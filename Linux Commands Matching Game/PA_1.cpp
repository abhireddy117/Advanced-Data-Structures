#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
// Making a node struct containing a data int and a pointer
// to another node
struct Node { 
    string cmd;
    string meaning;
    Node *next; 
};

class LinkedList
{
    // Head pointer
    Node* head;
    string playerName;
    int playerPoints,noOfQues;

  public:
    // default constructor. Initializing head pointer
    LinkedList()
    {
      head = NULL;
      playerPoints = 0;
    }

    // inserting elements (At start of the list)
    void insert(string cmd, string cmdMeaning)
    {
      // make a new node
      Node* new_node = new Node;
      
      new_node->cmd = cmd;

      new_node->meaning = cmdMeaning;

      new_node->next = NULL;

      // If list is empty, make the new node, the head
      if (head == NULL)
        head = new_node;
      // else, make the new_node the head and its next, the previous
      // head
      else
      {
        new_node->next = head;
        head = new_node;
      }
    }
    
    void remove(string cmd)
    {
      // If the head is to be deleted
      if (head->cmd == cmd)
      {
        delete head;
        head = head->next;
        return;
      }

      // If there is only one element in the list
      if (head->next == NULL)
      {
        // If the head is to be deleted. Assign null to the head
        if (head->cmd == cmd)
        {
          delete head;
          head = NULL;
          return;
        }
        // else print, value not found
        cout << "Value not found!" << endl;
        return;
      }

      // Else loop over the list and search for the node to delete
      Node* temp = head;
      while(temp->next!= NULL)
      {
        // When node is found, delete the node and modify the pointers
        if (temp->next->cmd == cmd)
        {
          Node* temp_ptr = temp->next->next;
          delete temp->next;
          temp->next = temp_ptr;
          return;
        }
        temp = temp->next;
      }

      // Else, the value was neve in the list
      cout << "Value not found" << endl;
    }

    void display()
    {
      Node* temp = head;
      while(temp != NULL)
      {
        cout << temp->cmd << " "<<temp->meaning<<"\n";
        temp = temp->next;
      }
      cout << endl;
    }
    
    void playGame(){
		
		char option;
		Node* temp = head;
		Node* nodeForMeaning;
		cout<<"Enter your name";
		cin>>playerName;
		cout<<"Enter the number of question you would like to answer from 1-30";
		cin>>noOfQues;
		int i=0;
		while(i<noOfQues)
		{
			nodeForMeaning = temp;
			cout<<nodeForMeaning->cmd<<"\n";
			cout<<"a)"<<nodeForMeaning->meaning<<"\n";
			cout<<"b)"<<nodeForMeaning->next->meaning<<"\n";
			cout<<"c)"<<nodeForMeaning->next->next->meaning<<"\n";
			temp = temp->next;
			cin>>option;
			if(option == 'a'){
				playerPoints = playerPoints + 1;
			}
			else
			{
				playerPoints = playerPoints - 1;
			}
			i++;
		}
		cout<<"Your score is"<<playerPoints<<"\n";
		storeData();
		return;
	}
	
	void storeData(){
		ofstream out("Players.csv", ios::app);
		if(out.is_open()){
		out << playerName<<","<<playerPoints<<"\n";
		out.close();
		}
		else
		{
			cout<<"not able to write into file";
		}
		return;
	}
	
	void loadPrevious()
	{
		ifstream in;
		string name,tempName,line;
		string playerPoint;
		cout<<"Enter your name which you used for old game";
		cin>>name;
		in.open("Players.csv");
		while(getline(in,line))
		{
			stringstream s(line);
			getline(s,tempName,',');
			if(tempName==name)
			{
				getline(s,playerPoint);
				playerName = tempName;
				stringstream geek(playerPoint);
				geek>>playerPoints; 
				break;
			}
		}
		return;
	}
	
	void writeLLtoFile()
	{
		Node* temp = head;
		ofstream out("Commands.csv");
		if(out.is_open()){	
			while(temp!=NULL)
			{
				out << temp->cmd << ","<<temp->meaning<<"\n";
        		temp = temp->next;
			}
			out.close();
		}
		else
		{
			cout<<"not able to write into file";
		}
		return;
		
	}
};


/*
Advantages of using an Array:
*Array can be used to reprasent multiple data items using a single name.
*Can accesed elements randomly using index numbers
*Two-dimensional arrays are used to represent matrices
Dis-advantages using an array:
*Number of elements stored should be known.
*Insertion and deleition are difficult in an array.
*The size of array cannot be modified. 





Advantages of Using an Linked List:
*Insertion and deletion of nodes is really easy.
*linked list can change size at runtime, it dose not waste no memmory.
*
dis-advantages of Using an Linked List:
*more memmory is used to store elements in linked list than in array.
*cannot access elements randomly. 

*/
int main() {
ifstream in;
in.open("Commands.csv");
string line,com,comMeaning;
LinkedList l;
int option; 
string insertCommand, insertCommandMeaning;

  // inserting elements


while (getline(in, line)) {
stringstream s(line);
getline(s,com,',');
getline(s,comMeaning);
l.insert(com,comMeaning);
}
      cout<<"\n"<<"\n"<<"\n";  
  do{
	cout<<"Please select an option listed below"<<"\n";
  cout<<"1. Game rules"<<"\n";
  cout<<"2. Play Game"<<"\n";
  cout<<"3. Load Previous Game"<<"\n";
  cout<<"4. Add command"<<"\n";
  cout<<"5. Remove command"<<"\n";
  cout<<"6. Exit"<<"\n";
  cin>>option;
  switch(option)
  {
  case 1:
	  cout<<"In this Game you can choose up to 30 questions to play." << endl;
	  cout<<"correct answer is 1 point, wrong answer is -1 point." <<endl;
	  cout<< "you will be given three options to choose from, in which one will be correct" <<endl;
	  cout<<" Good Luck" <<endl;
	  break;
  case 2:
  	l.playGame(); 
  	break;
  case 3:
  	l.loadPrevious();
  	break;
  case 4:
	cout<<"Please enter the command\n";
	cin>>insertCommand;
	cout<<"Please enter the command meaning\n";
	cin.ignore();
	getline(cin, insertCommandMeaning);
	l.insert(insertCommand, insertCommandMeaning);
	break;
  case 5:
 	cout<<"Please enter command to be removed";
 	cin>>com;
 	l.remove(com);
	break;
  default:
	  l.writeLLtoFile();
	  break;
  }	  
  }while(option<=5);
   
}