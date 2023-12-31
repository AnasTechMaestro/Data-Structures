#include <iostream>
using namespace std;

class node
{
    public:
    node *next;
    int data;
    node (int val){
        data=val;
        next=NULL;
    }
};

class Stack
{
    private:
        node *top;
        int length;
        int size;
    
    public:
        Stack(){
            top=NULL;
            length=0;
            size=10;
        }

        void push(int val);
        void display();
        int pop();

        int peek(){
            return top->data;
        }

        bool isEmpty();

        int getSize();
        void getSize(int size){
            this->size= size;
        }
        

        
};

int main()
{
    Stack s1,s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.pop();

    s1.display();
    cout<< endl<< "Stack 1 size: "<<s1.getSize()<<endl;
    cout<< endl<< "Stack 2 size: "<<s2.getSize()<<endl;
    return 0;
}

int Stack:: getSize(){
    return this->length;
}

bool Stack:: isEmpty(){
    if (length==0)
        return true;
    else
        false;
}

int Stack:: pop(){
    node* curr=top;
    if (curr==NULL)
    {
        cout<<"List is empty: Stack underflow, return -1"<<endl;
    } 

    else{
        //node* curr=top;
        int data=curr-> data;
        top= curr->next;
        delete curr;
        length--;
        return data;
    }

}

void Stack::push(int val)
{
    if (length < size){
        node *t=new node(val);
        if (top==NULL){
            top=t;
            length++;
        } else {
            t->next=top;
            top=t;
            length++;
        }
    }
    else    
        cout<< "Stack is full: Overflow"<<endl;

}

void Stack:: display()
{
	node *curr=top;
	while (curr!=NULL){
		cout<< "Node: "<<curr->data<<endl;
		curr=curr->next;
	}
}
