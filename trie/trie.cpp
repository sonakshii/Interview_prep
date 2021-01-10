#include <iostream>
#include <unordered_map>
using namespace std;

class node{
    public:
    char data;
    unordered_map<char,node*>h;
    bool isterminal;

    node(char d)
    {
        data=d;
        isterminal=false;
    }
};

class Trie{
    node* root;

    public:
    Trie()
    {
        root=new node('\0');
    }

    //insertion
    void addword(char *word){
        node*temp=root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch=word[i];
            if(temp->h.count(ch)==0)
            {
                node*child=new node(ch);
                temp->h[ch]=child;
                temp=child;
            }
            else
            {
                temp=temp->h[ch];
            }
        }
        temp->isterminal=true;
    }

    //searching
    bool search(char *word)
    {
        node*temp=root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch= word[i];

            if(temp->h.count(ch)==1)
            {
                temp=temp->h[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->isterminal;//checks if last node is terminal.
    }
};

int main()
{
    char word[10][100]={"apple","ape","coder","sonakshi","sona","newsong","new"};

    Trie t;
    for(int i=0;i<7;i++)
    {
        t.addword(word[i]);
    }
    char searchword[100];
    cout<<"ENTER A WORD TO BE SEARCHED:"<<endl;
    cin.getline(searchword,100);

    if(t.search(searchword))
    {
        cout<<searchword<<" has been found."<<endl;
    }
    else
    {
        cout<<searchword<<" not found."<<endl;
    }
    
    return 0;
}