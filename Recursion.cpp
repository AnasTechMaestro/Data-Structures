#include <iostream>
using namespace std;

int fun(int x)
{
	if (x==1){
		cout<<x<<"----"<<endl;
		return x;
	}
	
	else{
		cout<<x<<"+"<<"fun("<<x-1<<")"<<endl;
		return x+fun(x-1);
	}
}

int even(int x)
{
	if(x==1){
		return x;
	}
	
	else{
		if(x%2==0)
		cout<<x<<endl;
		return even(x-1);
	}
}

int main(){
	even(20);
}
