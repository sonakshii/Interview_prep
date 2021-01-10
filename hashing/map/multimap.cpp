#include<iostream>
#include<map>//used for multimaps too
#include<string>
using namespace std;

int main()
{
    multimap<char,string>m;
    
    int n;
    cin>>n;

    //insert
    for(int i=0;i<n;i++)
    {
        char ch;
        string s;
        cin>>ch>>s;
        m.insert(make_pair(ch,s));
    }

    //delete
    auto it=m.begin();
    m.erase(it);

    //iterarting in a range
    auto it2=m.lower_bound('b');
    auto it3=m.upper_bound('d');
    for(auto it4 =it2;it4!=it3;it4++)
    {
        cout<<it4->second<<" ";
    }
    cout<<endl;

    //search
    auto f=m.find('c');
    if(f->second=="cat")
    {
        cout<<"found cat"<<endl;
    }

    //print 
    for(auto p:m)
    {
        cout<<p.first<<" -> "<<p.second<<endl;
    }

    return 0;
}