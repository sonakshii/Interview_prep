//sorted list is taken
#include <iostream>
#include <set>
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

    bool detect_loop(node* head)
    {
        node* fp=head;
        node* sp=head;
        while(fp and fp->next)
        {
            fp=fp->next->next;
            sp=sp->next;
            if(sp==fp)
                return true;
        }
        return false;
    }

    node* remove_loop(node* head)
    {
        auto sp=head,fp=head;
        while(fp and fp->next)
        {
            sp=sp->next;
            fp=fp->next->next;
            if(sp==fp)
                break;
        } 
        if(sp==fp)
        {
            sp=head;
            while(sp->next!=fp->next)
            {
                fp=fp->next;
                sp=sp->next;
            }
            fp->next=NULL;
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
    head= head->insertion(6,head);

    auto cur=head;
    auto temp=head;
    while(cur->next)
    {
        cur=cur->next;
    }
    while(temp->data!=2)
    {
        temp=temp->next;
    }
    cur->next=temp;
    //creating loop from 6 to 2

    cout<<head->detect_loop(head)<<endl;

    head=head->remove_loop(head);

    cout<<"After removing loop checking for loop"<<endl;
    cout<<head->detect_loop(head);

}