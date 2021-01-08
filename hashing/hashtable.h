#include <string>
using namespace std;

template<typename T>
class node
{
public:
    string key;
    T value;
    node<T> *next;

    node(string k,T v)
    {
        key=k;
        value=v;
    }
    ~node()
    {
        if(next!=NULL)
        {
            delete next;//recursive destructor call
        }
    }
};
template<typename T>
class Hashtable
{
    int cs;//current size
    int ts;//max arr size
    node<T>** buckets;

    void rehash()
    {
        node<T>** oldbuckets=buckets;
        int oldTs=ts;
        ts=ts*2;
        cs=0;
        buckets=new node<T>* [ts];
        for(int i=0;i<ts;i++)
        {
            buckets[i]=NULL;
        }

        //read elements from old table and insert in new table
        for(int i=0;i<oldTs;i++)
        {
            node<T>*temp=oldbuckets[i];
            if(temp!=NULL)
            {
                while(temp!=NULL)
                {
                    insert(temp->key,temp->value);
                    temp=temp->next;
                }
            //delete old table i bucket list
                delete oldbuckets[i];
            }
        }
        delete [] oldbuckets;
    }

    int hashFn(string key)
    {
        int L=key.length();
        int ans=0;
        int p=1;//37^0==1
        for(int i=0;i<L;i++)
        {
            ans+=key[L-i-1]*p;
            p=p*37;
            p%=ts;//value overflow na ho jaye
            ans%=ts;
        }
        return ans;
    }

public:
    Hashtable(int ds=7)
    {
        cs=0;
        ts=ds;
        buckets=new node<T>*[ts];
        for(int i=0;i<ts;i++)//making all addresses as NULL
        {
            buckets[i]=NULL;
        }
    }
    void insert(string key,T value)
    {
        //key i need the hash-index
        int i=hashFn(key);

        node<T>*n=new node<T>(key,value);
        n->next=buckets[i];
        buckets[i]=n;//seperate chaining at head

        cs++;
        float load_factor=(float)cs/ts;
        if(load_factor>.7)
        {
            cout<<"Load factor is "<<load_factor<<endl;
            rehash();
        }
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            node<T>*temp=buckets[i];
            cout<<"Bucket "<<i<<"->";
            while(temp!=NULL)
            {
                cout<<temp->key<<", "<<temp->value<<" || ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    T* search(string key)
    {
        int i= hashFn(key);
        node<T> *temp=buckets[i];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &(temp->value);
            }
            temp=temp->next;
        }
        //what if key not found;
        return NULL;
    }

    
};