#include<iostream>
#include<iomanip>
using namespace std;
#define MAX 10
class Hash
{
 struct node
 {
  string title, artist ;
  int duration, r_year, music_no;
  struct node *next;
 };
node* ht[MAX];
public: 
 Hash()
 {
 int i;
 for(i=0;i<MAX;i++)
    ht[i]=NULL;
 }
   void insert();
   void deleter();
   void display();
   void search();
   void update();
 };
void Hash::display()
{
 node *ptr;
 int i;
 cout<<"HASH TABLE\n";
cout<<"|"<<setw(10)<<"Index"<<"|"<<setw(10)<<"Music_no"<<"|"<<setw(10)<<"Title"<<"|"<<setw(10)<<"Artist"<<"|"<<setw(10)<<"Duration"<<"|"<<setw(10)<<"Release_Year"<<"|"<<endl;
for(i=0;i<MAX;i++)
 {
  ptr=ht[i];
  cout<<"\n"<<"|"<<setw(10)<<i<<"::";
     while(ptr!=NULL)
   {
   	cout<<"|";
   	cout<<setw(10);
   	cout<<ptr->music_no;
   	cout<<"|";
   	cout<<setw(10);
    cout<<ptr->title;
	cout<<"|";
	cout<<setw(10);
    cout<<ptr->artist;
    cout<<"|";
    cout<<setw(10);
    cout<<ptr->duration;
    cout<<"|";
    cout<<setw(10);
    cout<<ptr->r_year;
    cout<<"|";
    ptr=ptr->next;
     } 
 }
}
void Hash::insert()
{
 int addr;
 node *ptr,*temp;
 temp=new node;
 cout<<"Enter the music no.::";
 cin>>temp->music_no;
 cout<<"Enter the music title track::"; 
 cin>>temp->title;
 cout<<"Enter the music artist::";
 cin>>temp->artist;
 cout<<"Enter the music duration::";
 cin>>temp->duration;
 cout<<"Enter the year of music release::";
 cin>>temp->r_year;
 addr=temp->music_no % MAX;//Mapped Location
 //get memory for the  new node
  temp->next=NULL;
 if(ht[addr]==NULL)
{   
    ht[addr]=temp;
 }
else
  {
   //locate the last node of the linked list
    ptr=ht[addr];
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
    ptr->next=temp; 
cout<<addr ;
}
}
void Hash::search()
{
 int addr,key;
node *ptr;
 cout<<"\nEnter the music no to be searched:";
 cin>>key;
 addr=key%MAX;
 ptr=ht[addr];
 while(ptr!=NULL && key!=ptr->music_no)
{   ptr=ptr->next;
}
  if(key==ptr->music_no)
   {
    cout<<ptr->music_no<<"\nKey Found at location::"<<addr;
   // break;
   }
}
void Hash::deleter()
{
 int addr,key;
 node *ptr,*temp,*prev;
 cout<<"Enter Music no for record to be deleted::";
 cin>>key;
 addr=key % MAX;//Mapped Location
 prev=ptr=ht[addr];
 if(ptr->music_no==key)
{
prev=prev->next;
ht[addr]=prev;
delete(ptr);
}
else
{
 while(ptr->next!=NULL && ptr->music_no!=key)
 {
  prev=ptr;
  ptr=ptr->next;
 }
if(ptr->music_no==key)
{
 prev->next=ptr->next;
 delete(ptr);
}
}
}

void Hash::update()
{
 int addr,key;
node *ptr;
 cout<<"\nEnter the music no to be updated:";
 cin>>key;
 addr=key%MAX;
 ptr=ht[addr];
 while(ptr!=NULL && key!=ptr->music_no)
{   ptr=ptr->next;
}
  if(key==ptr->music_no)
   {
    cout<<ptr->music_no<<"\nKey Found at location::"<<addr;
   // break;
 cout<<"\nEnter the new music title track::"; 
 cin>>ptr->title;
 cout<<"Enter the new music artist::";
 cin>>ptr->artist;
 cout<<"Enter the new music duration::";
 cin>>ptr->duration;
 cout<<"Enter the new year of music release::";
 cin>>ptr->r_year;
   }
}

int main()
{
      Hash h;
     
     int choice,ch;
     do
     {
         cout<<"\n----------------------"<<endl;
         cout<<"Operations on Hash Table"<<endl;
         cout<<"\nMusic Library System"<<endl;
         cout<<"\n----------------------"<<endl;
         cout<<"1.Insert music track into the table"<<endl;
         cout<<"2.Search music track from the key"<<endl;
         cout<<"3.Delete music track at a key"<<endl;
         cout<<"4.Display"<<endl;
         cout<<"5.Update"<<endl;
         cout<<"6.Exit"<<endl;
         cout<<"Enter your choice: ";
         cin>>choice;
         switch(choice)
         {
         case 1:
             h.insert();
             break;
         case 2:
           	h.search();
                break;
         case 3:
             h.deleter();
             break;
         case 4:
             h.display();
             break;
         case 5:
             h.update();
             break;
         case 6:
           //cout<<"\nEnter correct option\n";
           exit(0);
        }
        
cout<<"\nDo you want to continue";
cin>>ch;
}while(ch==1);
return 0;
}
