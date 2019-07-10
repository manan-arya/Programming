#include<iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* swap_nodes(node *head,int i,int j)
{
    //write your code here
    node *temp = head;
    
    for(int l=0;l<i-1 && temp -> next != NULL;l++)
    {
        temp = temp -> next;
    }
    
    node *p1 = temp;
    node *c1 = temp -> next;
    
    temp = head;
    for(int l=0;l<j-1 && temp->next != NULL;j++)
        temp = temp -> next;
    
    node *p2 = temp;
    node *c2 = temp->next;
    
    p1->next = c2;
    p2->next = c1;
    c1->next = c2->next;
    c2->next = p2;

    return head;
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}
