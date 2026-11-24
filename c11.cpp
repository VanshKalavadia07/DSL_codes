#include <iostream>
using namespace std;

class HeapSort
{
    int a[20];
    int n;

public:
void read(){
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
        }
    }
void heapify(int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left < n && a[largest] < a[left]){
        largest=left;
    }
    if(right < n && a[largest] < a[right])
    {
        largest=right;
    }
    if (largest !=i){
        int temp= a[i];
        a[i]=a[largest];
        a[largest]=temp;

        heapify(n,largest);
    }
    }
void sort(){
    for(int i=n/2 -1 ; i>=0;i--){
        heapify(n,i);
    }
    for(int i=n-1;i>0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;

        heapify(i,0);
    }
}
void display(){
    cout << "Sorted Elements:\n";
    for (int i=0; i<n;i++){
        cout << " " <<a[i];
    }
}
};
int main(){
    HeapSort h;
    h.read();
    h.sort();
    h.display();
}
