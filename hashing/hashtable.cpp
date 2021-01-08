#include<iostream>
#include "hashtable.h"
using namespace std;
int main()
{
    Hashtable<int> h;
    h.insert("Mango",100);
    h.insert("Apple",170);
    h.insert("Guava",140);
    h.insert("Banana",130);
    h.insert("Chiku",120);

    h.print();
    string f;
    cout<<"enter string: ";
    cin>>f;
    int *price =h.search(f);
    if(price==NULL)
    {
        cout<<"NOT FOUND"<<endl;
    }
    else
    {
        cout<<"price is: "<<*price<<endl;
    }

    return 0;
} 