#include <iostream>
#include <stack>
using namespace std;
#define MAX 5

class Queue {
private:
     int arr[MAX];
     int front, rear;

public:
     Queue(){
     front = -1;
     rear = -1;
     }

     void enqueue(int value){

     if (rear == MAX - 1){
     cout<< "Queue Overflow, Cannot Insert "<< value <<endl;
     return;
     }


     if (front == -1)
     front = 0;

     rear++;
     arr[rear] = value;
     cout <<value<< "Inserted into the queue."<<endl;
     }

     void dequeue() {
        if(front == -1 || front > rear) {
            cout<<"Queue Underflow, Queue is empty." << endl;
            return;
        }

        cout << arr[front] <<"deleted from the queue"<<endl;
        front++;

        if (front > rear){
            front = rear = -1;
        }
     }

     void display(){
        if (front == -1) {
            cout<<"queue is empty"<<endl;
            return;
        }

        cout<<"queue elements: ";
        for (int i = front; i <= rear; i++){
            cout<<arr[i] <<" ";
        }
        cout<<endl;

     }
};

int main() {
    Queue q;
    int choice, value;

    do{
        cout<<"\n-----Queue operations-----";
        cout<<"\n1. Enqueue";
        cout<<"\n2. Dequeue";
        cout<<"\n3. Display";
        cout<<"\n4. Exit";
        cout<<"\n Enter your choice: ";
        cin>> choice;

        switch(choice) {
    case 1:
        cout<<"Enter value to insert: ";
        cin >> value;
        q.enqueue(value);
        break;

    case 2:
        q.dequeue();
        break;

    case 3:
        q.display();
        break;

    case 4:
        cout<<"Exiting program..."<<endl;
        break;

    default:
        cout<<"Invalid choice, Try again."<< endl;
        }

    }while (choice != 4);

    return 0;


}
