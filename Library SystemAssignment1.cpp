/* . A library needs to manage a collection of books (data fields such as book title, author, ISBN, availability
status, and other relevant information), maintain information about each book, support operations like
adding, removing, and searching for books, and provide efficient access to library resources. Use the
Concept of Linked List for implementation of Library Management system.*/
#include<iostream>
using namespace std;
int n,i;
class library
{
    public:
    int ISBN;
    char *title,*author;
    void addBook();
    void search();
    void remove();
    void display();
}b[10];
void library :: addBook()
{
    title=new char;
    author=new char;
    cout<<"\nEnter Book ISBN no: ";
    cin>>ISBN;
    cout<<"Title :";
    cin>>title;
    cout<<"Author name: ";
    cin>>author;
    
};
void library :: search()
{
    int s,f=0;
    cout<<"\nEnter book ISBN no. which we want to search: ";
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(b[i].ISBN==s)
        {
            f=1;
            cout<<"\nBook is found";
            cout<<"\nISBN\tTITLE\tAUTHOR";
            b[i].display();
            break;
        }
    }
    if(f==0)
    {
        cout<<"\nBook is not found.";
    }
};
void library :: remove()
{
    int d,f=0;
    cout<<"\nEnter book ISBN no. which we want to delete: ";
    cin>>d;
    for(int i=0;i<n;i++)
    {
        if(b[i].ISBN==d)
        {
            f=1;
            cout<<"\nRecord deleted successfully";
            n--;
            break;
        }
    }
    if(f==0)
    {
        cout<<"\nRecord is not found";
    }
};
void library :: display()
{
    cout<<"\n"<<ISBN<<"\t"<<title<<"\t"<<author;
};
int main()
{
    int ch;
    char press;
    cout<<"\nEnter total no. of books :";
    cin>>n;
    do{
        cout<<"\nEnter your choice: ";
        cout<<"\n1.ADD BOOK\n2.DISPLAY\n3.SEARCH\n4.REMOVE\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            for(i=0;i<n;i++)
            {
                b[i].addBook();
            }
            cout<<"Added successfully";
            break;
            case 2:
            cout<<"\nAvailable books: ";
            cout<<"\nISBN\tTITLE\tAUTHOR";
            for(i=0;i<n;i++)
            {
                b[i].display();
            }
            break;
            case 3:
            b[i].search();
            break;
            case 4:
            b[i].remove();
            break;
        }
        cout<<"\nDo you want to continue Y/N: ";
        cin>>press;
    }while(press=='y'||press=='Y');
}