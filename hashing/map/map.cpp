#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,int>m;
    
    //insert
    //1 
    m.insert(make_pair("a",100));
    //2
    pair<string,int>p;
    p.first="b";
    p.second=110;
    m.insert(p);
    //3
    m["c"]=120;


    //search
    //1
    string ch;
    cin>>ch;

    auto it=m.find(ch);//retruns iterator at ch position

    if(it!=m.end())
    {
        cout<<ch<<" = "<<m[ch]<<endl;
    }
    else
    {
        cout<<"NOT FOUND"<<endl; 
    }

    //2
    if(m.count(ch))//returns 0 if present and 1 if not present
    {
        cout<<ch<<" = "<<m[ch]<<endl;
    }
    else
    {
        cout<<"NOT FOUND"<<endl; 
    }

    //delete
    //1
    m.erase(ch);

    //update
    m["a"]+=20;

    //to iterate over all keys
    //1
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" and "<<it->second<<endl;
    }

    //2
    for(auto p:m) 
    {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    return 0;
}