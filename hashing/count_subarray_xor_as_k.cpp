#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,s=0,c=0;
    cout<<"ENTER N"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"ENTER M"<<endl;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        s=0;
        for(int j=i;j<n;j++)
        {
            s=s^a[j];
            if(s==m)
            {
                c=c+1;
            }
        }
    }
    cout<<c;

    return 0;
}