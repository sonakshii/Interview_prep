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

    node* merge(node* h1,node* h2)
    {
        if(h1==NULL or h2==NULL)
        {
            return (h1==NULL)?h2:h1;
        }
        if(h1->data<h2->data)
        {
            h1->next=merge(h1->next,h2);
            return h1;
        }
        else
        {
            h2->next=merge(h1,h2->next);
            return h2;
        }
    }

    node* mergesort(node *head)
    {
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        auto sp=head,fp=head,pre=sp;
        while (fp and fp->next)
        {
            pre=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        pre->next=NULL;
        auto h1=mergesort(head);
        auto h2=mergesort(sp);
        return merge(h1,h2);
    }

};
int main()
{
    node* head=NULL;//creation
    head= head->insertion(1,head);//insertion
    head= head->insertion(4,head);
    head= head->insertion(2,head);
    head= head->insertion(5,head);
    head= head->insertion(6,head);
    head= head->insertion(3,head);

    cout<<"BEFORE SORTING"<<endl;
    head->print(head);//displaying

    head=head->mergesort(head);

    cout<<"AFTER SORTING"<<endl;
    head->print(head);
}
