#include <iostream>
using namespace std;

class node
{
public:
    int data ;
    node* next;
    //constructor
    node(int d)
    {
        this->data =d;
        this->next=NULL;
    }

    node* insertion(int d,node* head)
    {
        if(head==NULL)//new node
        {
            node* temp=new node(d);
            head=temp;
        }
        else//insertion at last
        {
            node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            node* z=new node(d);
            temp->next=z;
        }
        return head;
    }

    void print(node* head) //prints wholelist
    {
        auto temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    
    int middle(node* head)//finds middle element
    {
        auto sp=head,fp=head;
        while(fp!=NULL and fp->next!=NULL)
        {
            sp=sp->next;
            fp=fp->next->next;
        }
        return sp->data;
    }

    node* delete_mid(node* head)
    {
        auto sp=head,fp=head;
        auto pre=sp;
        while(fp!=NULL and fp->next!=NULL)
        {
            pre=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        pre->next=sp->next;
        delete sp;
        return head;
    }

    node* deletion(node* head)
    {
        auto pre=head;
        head=head->next;
        if(head==NULL)
        {
            delete pre;
        }
        while(head!=NULL)
        {
            delete pre;
            pre=head;
            head=head->next;
        }
        return head;
    }



};

int main()
{
    node* head=NULL;//creation
    head= head->insertion(1,head);//insertion
    head= head->insertion(2,head);
    head= head->insertion(3,head);
    head= head->insertion(4,head);
    head= head->insertion(5,head);

    head->print(head);//displaying

    cout<<head->middle(head)<<endl;//finding middle element

    head=head->delete_mid(head);//delete middle
    head->print(head);

    head=head->deletion(head);//delete whole list
    if(head!=NULL)
    {
        head->print(head);
    }
    else
    {
        cout<<"linked list is empty"<<endl;
    }
}