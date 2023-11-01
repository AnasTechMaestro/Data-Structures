#include <iostream>
#include <list>
using namespace std;

class Graph{
	//importedlibrary list's ka object
	list<int> *adjlist; //array of linkedlist type but data in node is int type.
	int vertex; //no of vertices
	
	public:
		Graph(int v){
			vertex=v;
			adjlist= new list<int>[vertex]; //array
		}
		
		void addEdge(int firstV, int secondV, bool bi){
			adjlist[firstV].push_back(secondV); //push back is built in func to add node in linked list  
			if (bi)
				adjlist[secondV].push_back(firstV);
		}
		
		void print(){
			//list<int>::iterator x;
			for (int i=0;i<vertex;i++){
				cout<<"Adj of: "<<i<<": ";
				for (auto it:adjlist[i]){
					cout<<it<<" ";
				}
				cout<<endl;
			}
		}
		
		void AdjacentNode(int n){
			for (auto it:adjlist[n]){
					cout<<it<<" ";
				}
		}
};


int main(){
	Graph g(6);
	g.addEdge(1,2, true);
	g.addEdge(1,5, true);
	g.addEdge(2,3, true);
	g.addEdge(2,4, true);
	g.addEdge(2,5, true);
	g.addEdge(3,4, true);
	g.addEdge(5,4, true);
	//for directed graph simply add false
	g.print();
	int n;
	cout<<"Enter vertix to see adj nodes ";
	cin>>n;
	g.AdjacentNode(n);
	
}
