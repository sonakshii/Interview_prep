#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main()
{

    int n,m,s=0,c=0; 
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    unordered_map<int,int>h;
    m=0;
    s=0;
    for(int i=0;i<n;i++)
    {
        s=s+A[i];
        if(s==0)
        {
            m=i+1;
        }
        else
        {
            if(h.find(s)!=h.end())
            {
                m=max(m,i-h[s]);
            }
            else
            {
                h[s]=i;
            }
        }
    }
    cout<< m;
}