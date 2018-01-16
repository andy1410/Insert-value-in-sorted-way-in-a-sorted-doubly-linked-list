#include<iostream>
#include<cstdio>
using namespace std;

struct node
{
    int data;
    node *next;
};
int main()
{
    int n,i;
    cout<<"Enter the size of list"<<endl;
    cin>>n;
    node *head=NULL,*p,*temp;
    for(i=0;i<n;i++)
    {
        p=new node();
        cout<<"Enter the data"<<endl;
         cin>>p->data;
         p->next=NULL;

         if(head==NULL)
            head=p;
         else
         {
             temp=head;
             while(temp->next!=NULL)
             {
               temp=temp->next;
             }
             temp->next=p;
         }
            }
            temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data;
                temp=temp->next;
            }
            return 0;
}
