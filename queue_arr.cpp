#include <iostream>
using namespace std;

	class Queue{
    private:
    int *arr;
    int size;
    int rear,front;
    int noOfElements;

    public:

    Queue(int size){
        this->size=size;
        arr=new int[size];
        rear=-1, front=-1, noOfElements=0;
    }

    ~Queue(){
        delete [] arr;
    }

    void enqueue(int val){
        if(rear==size-1){
            cout<<"stack overflow"<<endl;
            return;
        }

        if (front==-1)
            front=0;
        
        arr[++rear]=val;
        noOfElements++;
    }

    int dequeue(){
        if(front==-1){
            cout<<"queue underflow";
            return -1;
        }

        else{
            cout<<"element deleted from qyueue is: "<< arr[front]<<endl;
            return arr[front++];
        }


    }

    void display(){
        if(front==-1)
            cout<<"queue empty"<<endl;
        else{
            cout<< "QUEUE ELEMENTS ARE: ";
            for(int i=front; i<=rear ; i++)
            cout<< arr[i]<< " ";
            cout<< endl;
        }
    }
};

int main()
{
    Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.dequeue();

    q1.display();
    return 0;
}
