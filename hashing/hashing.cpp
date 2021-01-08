#include <iostream>
#include <algorithm>
#include <map> //#include<unordered_map>
#include <string>
using namespace std;

int main() 
{
    map<string,int>m;//or unordered_map<string,int>m;
    
    //insert one
    m["Mango"]=100;
    //insert two
    m.insert(make_pair("Apple",120));

    //search one
    if(m.count("Apple")==1)//cout returns 1 if present and 0 if not present
        cout<<"price apple "<<m["Apple"]<<endl;

    m["Guava"]=m["Mango"]+99;
    if(m.count("Guava")==0)//cout returns 1 if present and 0 if not present
        cout<<"Guava doesn't exist";
    else
    {
        cout<<"Guava costs "<<m["Guava"]<<endl;
    }

    //delete one
    m.erase("Mango");

    //search two
    auto f=m.find("Mango");
    if(f!=m.end()) 
    {
        cout<<"Price of mango "<<(f->second)<<endl;
    }
    else
    {
        cout<<"Mango doesn't exist"<<endl;
    }
    

    //delete one    
}