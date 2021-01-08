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

    void print_reverse(node* head)
    {
        if(head==NULL)
        {
            return;
        }
        print_reverse(head->next);
        cout<<head->data<<" ";
    }

    auto reverse(node* head)
    {
        node *cur=head,*next=head,*pre=NULL;
        while(cur)
        {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
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

    cout<<"recurvise printing of linklist"<<endl;
    head->print_reverse(head);//printing reverse recursively
    cout<<endl;

    cout<<"reversing list"<<endl;
    head= head->reverse(head);
    head->print(head);
}