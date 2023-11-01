#include <iostream>
using namespace std;

class Stack
{
	private:
		int *arr;
		int size;
		int length;
		int top;

	public:
        Stack(int size){
            this->size=size;
            arr= new int[size];
            top=-1;
        }
    ~Stack(){
        delete []arr;
    }

    void push(int val){
        if (top==size-1){
            cout<<"Stack oveflow"<<endl;
            return; //to terminate no return functions
        }
        arr[++top]=val;
    }

    int pop(){
        if(top==-1){
            cout<<"sTACK UNDERFLOW"<<endl;
            return 0;
        }
            return arr[top];
    }
    
    void display(){
        for(int i=top; i>0; i--){
            cout<< "Item: "<<i+1<<": "<<arr[i]<<endl;
        }
    }
};

int main()
{
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.pop();
    s1.display();
    return 0; 

}
