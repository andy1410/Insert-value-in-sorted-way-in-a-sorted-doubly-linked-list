#include <iostream>
#include <cstdio>
using namespace std;

// structure for doubly linked list
struct Node
{
int data;
Node *next;
Node *prev;
};

Node* InsertData(Node *head,int data);
void  PrintList(Node *head);

//main function with size of list and data which is to be insert
int main()
{
	Node *head=NULL;//initially list is empty
	int n,i,data;
	cout<<"Enter the size of list"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	  { cout<<"Enter the data"<<endl;
	  	cin>>data;
        head=InsertData(head,data);// insert function call
      }
	   PrintList(head);
	   return 0;
}

//function for print, node of list in ascending order
void  PrintList(Node *head)
{
	Node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

//function for inserting node in shorted order
Node* InsertData(Node *head,int data)
{
	Node *temp,*p;
	p=new Node();
	p->data=data;
	p->next=NULL;
	p->prev=NULL;
    
	//if list is empty
	if(head==NULL)
	 {
	     head=p;
	     return head;
	 }
    
	 //if insert node is insert at head node
	 else if(head->data>=data)
     {
         p->next=head;
         head->prev=p;
         head=p;
         return head;
     }
    
     //if node is insert between in list or last of list
	 else
	 {
          temp=head;
        while(temp->next!=NULL)
            {
              if(temp->data>=data)
              {
                  p->next=temp;
                  p->prev=temp->prev;
                  (temp->prev)->next=p;
                  temp->prev=p;
                  return head;
              }
              temp=temp->next;
           }
	 }
    
     temp->next=p;  //if node insert at end of list
     p->prev=temp;
     return head;
}
