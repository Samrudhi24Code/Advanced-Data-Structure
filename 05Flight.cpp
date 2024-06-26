/* Group C Assignment 4 : Graph DS representation using Adjacency list for Flight path between cities program
on June 26, 2021
 Problem statement :
There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph.
Check whether the graph is connected or not. Justify the storage representation used.
*/
#include<iostream>
using namespace std;

struct node
{
	string data;
	int fuel;
	node *next;
};

class graph1
{
	public:
	
	node * Head[10];
	int v,e;
	
	void create();
	void display();
	void edge();
		
};

void graph1::create()
{
	cout<<"How many Vertices : ";
	cin>>v;
	cout<<"Enter Name of Cities : \n ";
	for(int i=0;i<v;i++)
	{
		Head[i]=new node;
		cin>>Head[i]->data;
		Head[i]->next=NULL;
	}
	
}

void graph1::display()
{
	node *n2;
		for(int i=0;i<v;i++)
     	{
		cout<<"\nSource :"<<Head[i]->data;
		 n2=Head[i]->next;
		 
		 while(n2!=NULL)
		 {
		 	cout<<"   Dest : "<<n2->data;
		 	cout<<"   Fuel Required : "<<n2->fuel;
		 	n2=n2->next;
		 }
		}
	
}

void graph1::edge()
{
	int i,j;
	string s,d;
	node *n1 ,*temp;
	cout<<"How many Edges : ";
	cin>>e;
	
	for( i=0;i<e;i++)
	{
		cout<<"Enter Source n Dest :";
		cin>>s>>d;
		
		for(j=0;j<v;j++)
		{
			if(s==Head[j]->data)
			  break;
		}
		
		n1=new node;
		n1->data=d;
		cout<<"\n Enter Fuel Required : ";
		cin>>n1->fuel;
		n1->next=NULL;
		
		temp=Head[j];
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
		temp->next=n1;
	}
	
}


int main()
{
	graph1 g1;
	g1.create();
	g1.edge();
	g1.display();
	
	return 0;
	
}

//* OUTPUT----------------------------------
How many Vertices : 3
Enter Name of Cities :
Pune
Solapur
Mumbai
How many Edges : 3
Enter Source n Dest :Pune Solapur

 Enter Fuel Required : 220
Enter Source n Dest :Solapur Mumbai

 Enter Fuel Required : 320
Enter Source n Dest :Mumbai Pune

 Enter Fuel Required : 420

Source :Pune   Dest : Solapur   Fuel Required : 220
Source :Solapur   Dest : Mumbai   Fuel Required : 320
Source :Mumbai   Dest : Pune   Fuel Required : 420
--------------------------------
Process exited after 65.54 seconds with return value 0
Press any key to continue . . .
