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

    node* oddeven(node* head)
    {
        auto o=head,e=head->next,temp=e;
        while(e!=NULL and e->next!=NULL)
        {
            o->next=e->next;
            o=o->next;
            e->next=o->next;
            e=e->next;
        }
        o->next=temp;
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
    head= head->insertion(6,head);

    head=head->oddeven(head);
    head->print(head);

}
