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

    node* delete_dup(node* head) //for sorted
    {
        node *temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data==temp->next->data)
            {
                node *z=temp->next;
                temp->next=z->next;
                delete z;
            }
            else
            {
                temp=temp->next;
            }
        }
        return head;
    }

    //for unsorted list we use hashing concept
    auto remove_dup(node* head)
    {
        set<int> s;
        auto cur=head;
        auto pre=cur;
        while(cur)
        {
            if(s.count(cur->data))
            {
                pre->next=cur->next;
                delete cur;
            }
            else
            {
                s.insert(cur->data);
                pre=cur;
            }
            cur=pre->next;
        }
        return head;
    }

};

int main()
{
    node* head=NULL;//creation
    head= head->insertion(1,head);//insertion
    head= head->insertion(1,head);
    head= head->insertion(2,head);
    head= head->insertion(2,head);
    head= head->insertion(3,head);
    head= head->insertion(3,head);

    head->print(head);//displaying

    cout<<"deleting duplicates for sorted list"<<endl;
    head=head->delete_dup(head);
    head->print(head);

    cout<<"deleting duplicates in unsorted list"<<endl;
    head=head->remove_dup(head);
    head->print(head);
}