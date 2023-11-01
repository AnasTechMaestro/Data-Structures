#include<iostream>
#include<list>
using namespace std;
class node{
	public:
	int startV;
	int endV;
	int cost;
};
class Graph{
	public:
		list<node> *adjList;
	int n;// no of nodes
	Graph(int v){
		adjList= new list<node>[v];
		n=v;
	}
	void addEdge(int startV, int endV, int cost){
		node *t= new node();
		t->startV=startV;
		t->endV=endV;
		t->cost=cost;
		adjList[startV].push_back(*t);
	}
	void print(){
		for (int i=0; i<n;i++)
		{
			for (auto  it = adjList[i].begin(); it != adjList[i].end(); it++)
  			{
		  		cout<<"Adjacent of: "<<it->startV  <<" ->  "<< it->endV <<" (w:"<< it->cost <<")"<<endl;
			}
			cout<<endl;
		}
		}
	void listAdjacentNodes(int n){
			for (auto  it = adjList[n].begin(); it != adjList[n].end(); it++)
  			{
		  			cout<<"Adjacent of: "<<it->startV  
				  	<<" ->  "<< it->endV <<" (w:"<< it->cost <<")"<<endl;
			}
	}
	void listAdjacentNodes1(int n){
		list<int> cmm; 
        	for (auto  it = adjList[n].begin(); it != adjList[n].end(); it++)
  			{
  				    cmm.push_back(it->endV);
		  			cout<<"Adjacent of: "<<it->startV  
				  	<<" ->  "<< it->endV <<" (w:"<< it->cost <<")"<<endl;
			}
			cout<<endl<<"That are not adjacent"<<endl;
			list<int>::iterator at;
			for (auto  it = adjList[n].begin(); it != adjList[n].end(); it++)
  			{
  				bool check=true;
  				
  				 for (auto  at = cmm.begin(); at != cmm.end(); at++)
  			     {
  			     	if (it->startV==*at)
  				    {
  				    	check= false;
					  }
				  }
				  if(check)
				  cout<<it->startV<<" ";
			}
	}
};

int main(){
  Graph g(5);
    g.addEdge(0, 1,4);
    g.addEdge(0, 2,3);
    g.addEdge(1, 3,2);
    g.addEdge(1, 2,5);
    g.addEdge(2, 3,7);
    g.addEdge(3, 4,2);
    g.addEdge(4, 5,6);
    g.addEdge(4, 1,4);
    g.addEdge(4, 0,4);
    g.print();
    int n;
    cout<<"Enter node number to see adjacent nodes:";
    cin>>n;
    g.listAdjacentNodes1(n);
}
