#include <iostream>
using namespace std;

struct Node{
    int bookID;
    Node *next;
    };

class ClgLib{
    private:
        Node *head;
    public:
        ClgLib()
        {
            head = nullptr;
        }

        void insertAtBeginning(int id)
        {
        Node *newnode= new Node();
        newnode->bookID= id;                                        //[id|next]
        newnode->next = head;
        head=newnode;
        cout << "Book ID: " << id <<" inserted at the beginning\n";
        }

        void insertAtEnd(int id)
        {
            Node *newNode= new Node();
            newNode->bookID= id;
            newNode->next= nullptr;
            if(head == nullptr)
            {
                head=newNode;
            }
            else
            {
                Node *temp = head;
                while (temp->next != nullptr)
                    {
                    temp=temp->next;
                    }
                temp->next=newNode;
            }
            cout << "Book ID:" << id << " inserted at the End\n";
        }

        void deletefrombeginning()
        {
            if(head == nullptr)
                cout << "The Library Book list is empty.\n";
            Node *temp =head;
            head =head->next;
            cout << "Book ID: " << temp->bookID << "removed from the beginning";
            delete temp;
        }

        void Display()
        {
        if (head == nullptr)
            cout << "The library book List is Empty";
        Node *temp =head;
        cout << "Current library list: ";
        while(temp !=nullptr)
        {
            cout << temp->bookID << " -> ";
            temp =temp->next;
        }
        cout << "NULL\n";
        }

        ~ClgLib()
        {
            while (head != nullptr)
            {
                Node *temp =head;
                head =head->next;
                delete temp;
            }
        }
};

int main()
{
    ClgLib list;
    int choice, id;

    do{
        cout << "\n========LIBRARY BOOK MANAGEMENT MENU=======\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Display List\n";
        cout << "5. EXIT\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter Book ID to Insert at Beginning\n";
            cin >> id;
            list.insertAtBeginning(id);
            break;
        case 2:
            cout << "Enter Book ID to Insert at End\n";
            cin >> id;
            list.insertAtEnd(id);
            break;
        case 3:
            list.deletefrombeginning();
            break;
        case 4:
            list.Display();
            break;
        case 5:
            cout << "Exiting the Program----------------------------";
            break;
        default:
            cout << "Invalid Choice! Please Enter a Valid choice";
        }
    } while(choice !=5);
    return 0;
}
