#include <iostream>
#include <unordered_map> 
#include <string>
#include <vector>
using namespace std;

int main() 
{
    unordered_map<string,vector<int>>phonebook;
    
    phonebook["Rahul"].push_back(9191);
    phonebook["Rahul"].push_back(9192);
    phonebook["Rahul"].push_back(9193);
    phonebook["Rahul"].push_back(9194);
    phonebook["Rahul"].push_back(9195);

    phonebook["Kajal"].push_back(9111);
    phonebook["Kajal"].push_back(9112);
    phonebook["Kajal"].push_back(9113);
    phonebook["Kajal"].push_back(9114);

    for(auto p:phonebook)
    {
        cout<<"NAME: "<<p.first<<endl<<"  PHONE NUMBERS: ";
        for(int s:p.second)
        {
            cout<<s<<"  ";
        }
        cout<<endl;
    }

    string name;
    cout<<"ENTER A NAME: ";
    cin>>name;
    if(phonebook.count(name)==0)
    {
        cout<<"NOT PRESENT IN PHONEBOOK"<<endl;
    }
    else
    {
        for(int s:phonebook[name])
        {
            cout<<s<<endl;
        }
    }
    

    return 0;
}